# Manual TBB Setup

1. Download [TBB Library](https://github.com/oneapi-src/oneTBB) and [GCC9](https://gcc.gnu.org/gcc-9/changes.html) compiler. Note: Since this version it allows to use the c++17 parallel implementations, i.e. with `std::parallel`. [Link to Release](https://gcc.gnu.org/gcc-9/changes.html)

2. Navigate to the TBB Library and run `make all`, this compiles the TBB library and creates a subfolder in the `build`-directory which includes the compiled version of TBB.

3. Setting the env-variables for the setup as mentioned in this SOF [post](https://stackoverflow.com/questions/10726537/how-to-install-tbb-from-source-on-linux-and-make-it-work).


```shell
# TBB Config as export
export TBB_INSTALL_DIR=$HOME/.TBB;
export TBB_INCLUDE=$TBB_INSTALL_DIR/include;
export TBB_LIBRARY_RELEASE=$TBB_INSTALL_DIR/build/YOUR_VERSION;
# seperate file, CMD for sourceing: ". .TBBconfig"
TBB_INSTALL_DIR=$HOME/.TBB;
TBB_INCLUDE=$TBB_INSTALL_DIR/include;
TBB_LIBRARY_RELEASE=$TBB_INSTALL_DIR/build/YOUR_VERSION;
```