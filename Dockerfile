FROM gcc:11


RUN apt-get -qq update \
    && apt-get -qq install --no-install-recommends openssh-server \
    && apt-get -qq install --no-install-recommends sudo \
    && apt-get -qq install --no-install-recommends cmake \
    && apt-get -qq install --no-install-recommends rsync \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# setup ssh for use ubuntu, password 1234
RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u 1000 ubuntu
RUN  echo 'ubuntu:1234' | chpasswd
RUN service ssh start
EXPOSE 22

# install google test
WORKDIR /usr/src/libraries
RUN git clone --depth=1 -b main https://github.com/google/googletest.git
WORKDIR /usr/src/libraries/googletest/build
RUN cmake .. \
    && make \
    && make install

# build the project
WORKDIR /usr/src/app
COPY . .
RUN rm -rf build
RUN mkdir build
WORKDIR /usr/src/app/build
RUN cmake ..
RUN make

# CMD ["/usr/sbin/sshd","-D"]
CMD ["./main"]

#FROM gcc:11
#
## 一次性安装所有依赖
#RUN apt-get update && apt-get install -y --no-install-recommends \
#    openssh-server \
#    sudo \
#    cmake \
#    rsync \
#    git \
#    && apt-get clean \
#    && rm -rf /var/lib/apt/lists/*
#
## 安装GoogleTest
#RUN git clone --depth=1 -b main https://github.com/google/googletest.git /tmp/googletest \
#    && cd /tmp/googletest \
#    && mkdir build && cd build \
#    && cmake .. && make && make install \
#    && rm -rf /tmp/googletest
#
## 设置工作目录
#WORKDIR /usr/src/app
#
## 拷贝代码
#COPY . .
#
## 构建项目
#RUN mkdir -p build && cd build && cmake .. && make
#
## 修复1：使用正确的CMD格式
#WORKDIR /usr/src/app/build
#CMD ["./main"]
#
## 或者修复2：使用shell格式
## CMD cd /usr/src/app/build && ./main