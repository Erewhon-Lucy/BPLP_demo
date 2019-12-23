<<<<<<< HEAD
# BPLP_demo
=======
# BPLP_demo

hahaha thz来了
>>>>>>> adae574e4ff1f162be2234143862f0cd8ba9000c

注意！readme更新了！

想要增加对中文的完美支持吗

还在等什么

快

```
sudo apt-get install libncurses5 libncursesw5 libncursesw5-dbg libncursesw5-dev 
```

再用 -lncursesw  链接全新库哦

别忘了在main函数第一行加上

```
setlocale(LC_ALL,"");
```

新增

Makefile：

框架不用改，需要合并运行的.c程序只需在sources后加上其名字即可

比如，一起编译一个叫做main.c的文件和face.c

```
sources = face.c main.c
```

现在的编译指令就是

```
make
```

输出文件叫做b