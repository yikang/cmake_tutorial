# cmake tutorial for learning purpose

## cmake common steps: 
```
mkdir build 
cd build 
cmake .. 
make 
make install # optinal
```

```
# make for specific  target 

make camera # only make library 
make main_test2 # only make for specific target

```

- CMakeLists.txt  


## build your own library from multiple sources 
- CMakeLists2.txt

1. build library and install

```
cmake .. 
sudo make install 
``` 

2. test usage
```
cmake -DBUILD_TEST=True ../
make
``` 