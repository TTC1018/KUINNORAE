#include "Room.h"
#include "kiosk.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

        Room::Room() { //constructor Initial: song: 0 , occupied:false(mean empty room)
            this->occupied = false;
            this->song_remain = 0;
            this->currentUser = nullptr;

        }

        void* Room::sing() {

            mutex *mu = &kiosk::getInstance()->mu;

            while (1) {
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));//sleep 5 sec -> 1 song each 5 sec
                mu->try_lock();
                if(song_remain > 0) this->song_remain--;
                mu->unlock();
            }

		} 

		int Room::getSong_remain() {
            return this->song_remain;
		}

		void Room::setSong_remain(int songInput) {
            this->song_remain = songInput;
		}

		bool Room::getOccupied() {
            return this->occupied;
		}

		void Room::setOccupied(bool status) {
            this->occupied = status;
		}
        User* Room::getCurrentuser() {
            return this->currentUser;
		}
        void Room::setCurrentuser(User *user) {
            this->currentUser = user;
		}
