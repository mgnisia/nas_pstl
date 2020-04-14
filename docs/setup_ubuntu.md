# Setup Ubuntu

⚠️ Assumption GCC9 is already installed if not [jump to setup](#gcc-9-setup)

1. `sudo apt-get update && sudo apt-get upgrade`
2. `sudo apt-get install -y build-essential libtbb-dev`

Copy Paste:

```shell
sudo apt-get update && sudo apt-get upgrade && sudo apt-get install -y build-essential libtbb-dev 
```

## GCC 9 Setup

```shell
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install gcc-9
```

