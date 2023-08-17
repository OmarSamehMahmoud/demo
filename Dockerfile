# Use an appropriate base image for your desired Linux distribution
FROM ubuntu:latest

# Install required dependencies
RUN apt-get update && apt-get install -y \
    wget \
    unzip \
    build-essential \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Install Arduino CLI
RUN wget -O- https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

# Set the working directory
# WORKDIR /app

# Copy the sketch file to the working directory
# COPY remote.ino .

RUN mkdir /home/app

COPY ./elarabyapp /home/app

WORKDIR /home/app

# Compile the sketch
RUN arduino-cli core update-index
RUN arduino-cli core install arduino:avr

# Specify the entry point command to run the sketch
CMD arduino-cli compile --fqbn arduino:avr:nano . && arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:nano .