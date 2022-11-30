// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <thread>
#include <future>
#include "TreasureMap.h"

namespace sdds
{

   size_t digForTreasure(const std::string& str, char mark) {
      size_t cnt = 0;
      for (auto& x : str) {
         if (x == mark) {
            cnt++;
         }
      }
      return cnt;
   }

   TreasureMap::TreasureMap(const char* filename) {
      std::fstream fin(filename);
      if (fin) {
         fin >> rows;
         fin.ignore();
         map = new std::string[rows];
         size_t idx = 0;
         while (fin) {
            getline(fin, map[idx]);
            idx++;
         }
         colSize = map[0].length();
      }
      else {
         throw std::string(filename) + " cannot be opened";
      }
   }

   TreasureMap::~TreasureMap() {
      delete[] map;
   }

   std::ostream& TreasureMap::display(std::ostream& os) const {
      if (map) {
         for (size_t i = 0; i < rows; ++i) {
            os << map[i] << std::endl;
         }
      }
      else
         os << "The map is empty!" << std::endl;
      return os;
   }

   void TreasureMap::enscribe(const char* filename) {
      // Binary write
      if (map) {
         // TODO: Open a binary file stream to the filename and
         //         then write the row number to the binary file 
         //         then each of the rows of the map.
         //       If the file cannot be open, raise an exception to
         //         inform the client.
        
         std::ofstream file(filename, std::ios::out | std::ios::binary);
         if (file) {
            file.write((const char*)&rows, sizeof(size_t));
            file.write((const char*)&colSize, sizeof(size_t));
            for (size_t i = 0; i < rows; i++) {
               file.write((const char*)&map[i][0], colSize);
            }
            file.close();
         }
         else {
            throw std::string("File could not be open!");
         }
         // END TODO
      }
      else {
         throw std::string("Treasure map is empty!");
      }
   }

   void TreasureMap::recall(const char* filename) {
      // Binary read
      // TODO: Open a binary file stream to the filename
      //         and read from it to populate the current object.
      //       The first 4 bytes of the file will be the number of rows
      //         for the map followed another 4 bytes for the colSize
      //         of each row in the map.
      //       Afterwards is each row of the map itself.
      //       If the file cannot be open, raise an exception to inform
      //         the client.

      std::ifstream file(filename, std::ios::in | std::ios::binary);
      if (file) {
         file.read((char*)&rows, sizeof(size_t));
         file.read((char*)&colSize, sizeof(size_t));
         map = new std::string[rows];
         for (size_t i = 0; i < rows; i++) {
            map[i].resize(colSize);
            file.read((char*)&map[i][0], colSize);
         }
         file.close();
      }
      else {
         throw std::string("File could not be open");
      }
      // END TODO
   }

   void TreasureMap::clear() {
      delete[] map;
      map = nullptr;
      rows = 0;
      colSize = 0;
   }

   size_t TreasureMap::findTreasure(char mark) {
      size_t count = 0;

      // TODO: For part 2, comment this "for" loop and write the multihreaded version.
     /* for (size_t i = 0; i < rows; ++i) {
         count += digForTreasure(map[i], mark);
      }*/

      auto digTreasure = std::bind(digForTreasure, std::placeholders::_1,mark);
      std::packaged_task<size_t(std::string&)>pt(digTreasure);
      std::packaged_task<size_t(std::string&)>pt2(digTreasure);
      std::packaged_task<size_t(std::string&)>pt3(digTreasure);
      std::packaged_task<size_t(std::string&)>pt4(digTreasure);
      auto f = pt.get_future();
      auto f2 = pt2.get_future();
      auto f3 = pt3.get_future();
      auto f4 = pt4.get_future();
      std::string str;
      std::string str2;
      std::string str3;
      std::string str4;

      // concatenating the string 
      size_t capacity = rows/4;
      for (size_t i = 0; i < rows; i++) {
         if (i < capacity) {
            str += map[i];
         }
         else if (i >= capacity && i < (2 * capacity)) {
            str2 += map[i];
         }
         else if (i >= (2 * capacity) && i < (3 * capacity)) {
            str3 += map[i];
         }
         else if (i >= (3 * capacity) && i < (4 * capacity)) {
            str4 += map[i];
         }
      }

      std::thread tX(std::move(pt),std::ref(str));
      std::thread tY(std::move(pt2),std::ref(str2));
      std::thread tZ(std::move(pt3),std::ref(str3));
      std::thread tW(std::move(pt4),std::ref(str4));;

      tX.join();
      tY.join();
      tZ.join();
      tW.join();
      count = f.get() + f2.get() + f3.get() + f4.get();


      return count;
   }
}