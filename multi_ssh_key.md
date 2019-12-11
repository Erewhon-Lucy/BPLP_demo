多对key放进.ssh之后，所有keygen（不管之前在不在）需要以下两步操作

```
ssh-agent bash
//如果unable to start ssh-agent service, error :1058
//小娜本地搜索“服务”将其中OpenSSH Authentication Agent设为自动
ssh-add C:\Users\本机用户名\.ssh\钥匙名
//cmder中为\分割 不确定可以照抄终端上一行输出的地址
```

同时需要一个没有后缀的名为config的文件（新建然后把后缀删了）

```
Host github.com//服务器
HostName github.com //服务器名
User 邮箱地址（创建git那时候的） 
PreferredAuthentications publickey
IdentityFile ~/.ssh/id_rsa 

Host git@www.kcjsj.cn
HostName git@www.kcjsj.cn
PreferredAuthentications publickey
IdentityFile ~/.ssh/钥匙名字
```

