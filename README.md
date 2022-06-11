# cmake tutorial for learning purpose

## cmake common steps: 
```
mkdir build 
cd build 
cmake .. 
make 
make install # optinal
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