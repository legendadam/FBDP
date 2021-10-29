# Hom5
* 在HDFS上加载莎士比亚文集的数据文件（shakespeare-txt）
* 编写MapReduce程序进行词频统计
* 按照单词出现次数从大到小排列
* 输出：
  * 每个作品的前100个高频单词
  * 所有作品的前100个高频单词
* 要求：
  * 忽略大小写
  * 忽略标点符号（punctuation.txt）
  * 忽略停词（stop-word-list.txt）
  * 忽略数字，单词长度>=3
  * 输出格式为"<排名>：<单~~~~词>，<次数>“
  * 输出可以根据作品名称不同分别写入不同的文件，也可以合并成一个文件
## 设计思路
### 在HDFS上加载莎士比亚文集的数据文件
* 将shakespeare-txt,punctuation.txt,stop-word-list.txt放入input文件夹中
* 主机C:\Users\adam\Desktop\input目录拷贝到容器h01的/usr/local/hadoop/input/目录下
  > docker cp C:\Users\adam\Desktop\input h01:/usr/local/hadoop/input/
* 容器h01的/usr/local/hadoop/input目录上传到HDFS的/user/root/目录中
  > $ cd /usr/local/hadoop
  > $ bin/hdfs dfs -put input input
### 
## 实验结果
