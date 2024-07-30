#!/bin/bash

if [ ! -d boost_1_80_0 ]; then
  echo "Boost не найден. Скачиваем с сайта..."
  wget -O boost_1_80_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.80.0/boost_1_80_0.tar.gz/download

tar xzvf boost_1_80_0.tar.gz
cd  boost_1_80_0/
./bootstrap.sh --prefix=/usr/
./b2
sudo ./b2 install
cd ..
  echo "Boost успешно скачан и установлен."
else
  echo "Boost уже установлен."
fi
