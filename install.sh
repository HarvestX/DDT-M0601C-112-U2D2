#!/usr/bin/env bash


# Setup Path
install_dir=$HOME/.local/src
mkdir -p $install_dir
cd $install_dir


# Install Dynamixel SDK
git clone git@github.com:ROBOTIS-GIT/DynamixelSDK.git -b v3.3.3

cd $HOME/.local/src/DynamixelSDK/c++/build/linux64
sudo make install

echo "Done!"

