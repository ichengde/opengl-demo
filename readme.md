# 示例项目 qt-opengl
### 完成点 线 绘画

opengl初始化流程在oepnglwindow文件中

qt opengl项目主要使用opengl es 2.0 版本
http://blog.csdn.net/myarrow/article/details/7692044
这里附上原始opengl说明文档

main中 进行了 参数的初始化 顶点着色器及片面着色器的编译 链接

该项目-自动生成大焦点及点之间的线
输入 点列表和少许改动即可

坐标系 大小限制在[0,1]!--重要
1. 面向我们是正z轴
2. 右手边是正x轴
3. 头顶是正y轴

点的控制列表-vertices
vertices需要与colors的数目保持一致

q&a:
1. 如何修改点大小
 找到vertexShaderSource中的gl_PointSize 修改成浮点数即可
2. 如何修改线粗细
 glLineWidth 修改成浮点数即可
3. 如何改变原元颜色
 修改colors 
4. 如何修改点坐标及数量
 修改vertices vertices需要与colors的数目保持一致