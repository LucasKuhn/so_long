# Installing MLX locally on MacOS

Requirements for MacOS
 - [Xquartz](https://www.xquartz.org/)

```bash
➜  ~ Brew install Xquartz
➜  ~ reboot
➜  ~ xeyes # run an hello world X11 app
```

I downloaded the compiled version from [here](https://github.com/taelee42/mlx_example)

> Test the examples. If they work on your machine, this compiled version works for you! :) 
1. Install the lib in your system: `cp mlx/libmlx.a /usr/local/lib`
2. Install the mlx headers in your system: `cp mlx/mlx.h /usr/local/include`
3. Install the manuals: `cp mlx/man3/* /usr/local/share/man/man3`