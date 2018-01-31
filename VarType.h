#pragma once
/*
VarType.h
功能：变量类型
-------------------------------------
类
class NeuroPoint
class Neuro_PointList
class Neuro_Mat
struct Neuro_EdgeNode
struct Neuro_VertexNode
class ALGraph
-------------------------------------
函数
enum MatType
-------------------------------------
测试
-------------------------------------
跟新：
2016-07-11 肖镇龙 初始化

*/

#ifndef __VARTYPE_H_
#define __VARTYPE_H_

#include <string>
#include <strstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stack>
#include <initializer_list>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <list>
//#include "Draw.h"

using namespace std;
typedef unsigned char uint8;
//typedef pair<pair<int, int>, pair<int, int> > RectSize;  //方框大小坐标，x, y, w, h
string num2str(const int num);
string num2str(const long num);
string num2str(const short num);
string num2str(const double num);
string num2str(const float num);
int str2int(const string num);
double str2double(const string num);
#define PI 3.14159265358979323846
//方框大小坐标，x, y, w, h

//uchar: CV_8UC1，CV_8UC2，CV_8UC3，CV_8UC4
//char: CV_8UC1，CV_8UC2，CV_8UC3，CV_8UC4
//ushort: CV_16UC1，CV_16UC2，CV_16UC3，CV_16UC4
//short: CV_16SC1，CV_16SC2，CV_16SC3，CV_16SC4
//int: CV_32SC1，CV_32SC2，CV_32SC3，CV_32SC4
//float: CV_32FC1，CV_32FC2，CV_32FC3，CV_32FC4
//double: CV_64FC1，CV_64FC2，CV_64FC3，CV_64FC4
enum MatType
{
	_NULL = -1,
	_8UC1 = 0,	_8SC1,	_16UC1,	_16SC1,	_32SC1,	_32FC1,	_64FC1,
	_8UC2,		_8SC2,	_16UC2,	_16SC2,	_32SC2,	_32FC2,	_64FC2,
	_8UC3,		_8SC3,	_16UC3,	_16SC3,	_32SC3,	_32FC3,	_64FC3,
	_8UC4,		_8SC4,	_16UC4,	_16SC4,	_32SC4,	_32FC4,	_64FC4
};


class NeuroPoint
{
public:
	int x = 0;
	int y = 0;
	int z = 0;
	NeuroPoint() {};
	NeuroPoint(int, int);
	NeuroPoint(int, int, int);
	NeuroPoint(const initializer_list<int> &list);
	NeuroPoint(const NeuroPoint &pt2);
	NeuroPoint &operator=(const NeuroPoint &pt2);
	void Print()const;
	int *GetData();
	bool operator== (const NeuroPoint &p2);
	bool operator!= (const NeuroPoint &p2);
	friend bool operator== (const NeuroPoint &p1, const NeuroPoint &p2);
	friend bool operator!= (const NeuroPoint &p1, const NeuroPoint &p2);
	NeuroPoint operator+(const int &num);
	NeuroPoint operator-(const int &num);
	NeuroPoint operator*(const int &num);
	NeuroPoint operator/(const int &num);
	friend NeuroPoint operator+(const NeuroPoint &pt1, const NeuroPoint &pt2);
	friend NeuroPoint operator-(const NeuroPoint &pt1, const NeuroPoint &pt2);
	void Clear();
};

class NeuroPoint_d
{
public:
	double x = 0;
	double y = 0;
	double z = 0;
    NeuroPoint_d() {}
	NeuroPoint_d(double, double);
	NeuroPoint_d(double, double, double);
	NeuroPoint_d(const initializer_list<double> &list);
	NeuroPoint_d(const NeuroPoint_d &pt2);
	NeuroPoint_d &operator=(const NeuroPoint_d &pt2);
	NeuroPoint_d(const NeuroPoint &pt2);
	NeuroPoint_d &operator=(const NeuroPoint &pt2);
	void Print()const;
	double *GetData();
	bool operator== (const NeuroPoint_d &p2);
	bool operator!= (const NeuroPoint_d &p2);
	friend bool operator== (const NeuroPoint_d &p1, const NeuroPoint_d &p2);
	friend bool operator!= (const NeuroPoint_d &p1, const NeuroPoint_d &p2);
	NeuroPoint_d operator+(const double &num);
	NeuroPoint_d operator-(const double &num);
	NeuroPoint_d operator*(const double &num);
	NeuroPoint_d operator/(const double &num);
	friend NeuroPoint_d operator+(const NeuroPoint_d &pt1, const NeuroPoint_d &pt2);
	friend NeuroPoint_d operator-(const NeuroPoint_d &pt1, const NeuroPoint_d &pt2);
};

//vector
class Neuro_PointList
{
private:
	//NeuroPoint *list;
	vector<NeuroPoint> list;
	//int top = -1;
	//int capacity = 0;
	//int capacity_back = 0;
public:
	Neuro_PointList();
	Neuro_PointList(const int &in_capacity);
	Neuro_PointList(const Neuro_PointList &list2);
	Neuro_PointList &operator= (const Neuro_PointList &list2);
	bool operator<(const Neuro_PointList &list2);
	bool operator>(const Neuro_PointList &list2);
	//~Neuro_PointList();
	size_t size() const;
	int Capacity();
	void push(const NeuroPoint &pt);
	vector<NeuroPoint> GetList();
	void clear();
	NeuroPoint pop();
	bool isMatch(const NeuroPoint &pt);
	void PrintInfo();
	void PrintPt();
	NeuroPoint &at(const int &n);	// 返回第n个点
	NeuroPoint at_pt(const size_t &n)const;
	NeuroPoint at_pt(const int &n)const;	// 返回第n个点的NeuroPoint
	NeuroPoint at_pt(const long long &n)const;	// 返回第n个点的NeuroPoint
	bool isEmpty();
};

//List
class Neuro_PtList_linked
{
private:
	list<NeuroPoint> data;
public:
	Neuro_PtList_linked(){}
	Neuro_PtList_linked(const int &in_capacity);
	Neuro_PtList_linked(const Neuro_PtList_linked &list2);
	Neuro_PtList_linked &operator= (const Neuro_PtList_linked &list2);
	size_t size() const;
	void push(const NeuroPoint &pt);
	list<NeuroPoint> GetList();
	void clear();
	NeuroPoint pop();
	bool isMatch(const NeuroPoint &pt);
	void PrintInfo();
	void PrintPt();
	NeuroPoint &at(const int &n);	// 返回第n个点
	NeuroPoint at_pt(const size_t &n)const;
	NeuroPoint at_pt(const int &n)const;	// 返回第n个点的NeuroPoint
	NeuroPoint at_pt(const long long &n)const;	// 返回第n个点的NeuroPoint
	bool isEmpty();
	void unique();		//去掉重复项
	list<NeuroPoint>::iterator begin();
	list<NeuroPoint>::iterator end();
};

class iSharp
{
public:
    iSharp() {}
	virtual void print()const {}
};
class RectSharp :iSharp
{
public:
	pair<pair<int, int>, pair<int, int> > data;
	RectSharp(const int &x = 0, const int &y = 0, const int &w = 0, const int &h = 0) :data({ { x, y },{ w, h } }) {}
	RectSharp(const initializer_list<int> &rect_list) :data({ { rect_list.begin()[0], rect_list.begin()[1] },
	{ rect_list.begin()[2], rect_list.begin()[3] } }) {}
	int &at(const int &n);
	bool isIn(const NeuroPoint &pt)const;		//判断点pt是否在方框范围之内
	int x()const;
	int y()const;
	int w()const;
	int h()const;
	int RightDownX()const;
	int RightDownY()const;
	void print()const;
};

class ImSize :iSharp
{
public:
	int rows;
	int cols;
	int layers;

	ImSize(const int &rows = 0, const int &cols = 0, const int &layers = 1) :rows(rows), cols(cols), layers(layers) {}
	ImSize(initializer_list<int> size);
	void print()const;
};

template <class DataType>
class Neuro_Mat
{
private:
	DataType *data;
	vector<int> size;

};

//邻接表表节点
struct Neuro_EdgeNode
{
	size_t adjvertex;	//临接点域，顶点对应序号
	Neuro_EdgeNode *next = NULL;	//指向下一个邻接点的指针域
	bool pathVisited = 0;	//路径已访问标志
};

//邻接表顶点节点
struct Neuro_VertexNode
{
	NeuroPoint vertex;	//顶点域
	Neuro_EdgeNode *firstedge = NULL;	//边表头指针
	bool pathVisited = 0;	//路径已访问标志
	bool isBranchVertex = 0;	//是否为分支节点
	int OriNo = -1;			//顶点在原邻接表中的序号，保留字段
	void print() const;
};

//邻接表，以邻接表方式储存的图类型
class ALGraph
{
private:
	vector<Neuro_VertexNode> vertexs;		//邻接表
	vector<int> visited;	//访问数组标志

	/*DFS 所需 属性 变量*/
	vector<int> branchVertex;		// 分支节点的数组
	int visitedVertex = 0;      // 被访问的节点
	vector<Neuro_VertexNode> visitedEdge;        // 被访问的路径
	int originVertex = 0;       // 起始点
	vector<vector<int>> paths;              // 指定两点能够到达的所有通路
	int pathNum = 0;            // 指定两点之间符合条件的通路数量


	/*转成树形结构*/
	int tree = 0;               // 双亲表示
	int BFSsequence = 0;        // 队列

	static void MoveEdgeNum(Neuro_VertexNode &vertex, const size_t &move_num);// Move the number of edges of vertex. The number will be added by move_num.

	vector<Neuro_VertexNode> Reverse() const;	//不安全
	static vector<Neuro_VertexNode> Reverse(const vector<Neuro_VertexNode> &vertex_list);	//反转顶点顺序 不安全
	friend class figure; 
public:
	
	ALGraph();
	~ALGraph();
	ALGraph(const ALGraph &algraph2);
	ALGraph &operator=(const ALGraph &algraph2);
	void CreateGraph(const Neuro_PointList &vertex_list, const pair<vector<int>, vector<int> > &edge_list);	//建立图的存储矩阵成员函数
	void CreateGraph(const vector<Neuro_VertexNode> &vertex_list);
	void AddVertex(const NeuroPoint &vertex);							//添加一个点, 无连接信息
	void AddVertex(const NeuroPoint &vertex, const size_t &connect_point);		//添加一个点及其连接信息 connect_point应为在vertexs中的顶点
	void AddVertexList(const vector<Neuro_VertexNode> &vertex_list, const size_t &connect_point, const bool &dir);	//添加点列表及其连接信息
	void AddVertexList(const vector<Neuro_VertexNode> &vertex_list, const size_t &connect_point1, const size_t &connect_point2);
	void AddVertexList(const ALGraph &Graph, const size_t &connect_point, const bool &dir);
	void AddVertexList(const ALGraph &Graph, const size_t &connect_point1, const size_t &connect_point2);
	void AddConnect(const size_t &connect_point1, const size_t &connect_point2);	//纤维内部两个点之间建立连接关系
	vector<Neuro_VertexNode> &GetData();				//获取邻接表数据
	Neuro_PointList GetPointList();
	Neuro_VertexNode &at(const size_t &n);
	NeuroPoint GetPoint(const size_t &n)const;
	void Clear();									//清空数据
	Neuro_VertexNode Pop();					//弹出最后一个点，及其与其它点的连接关系
	size_t GetSize() const;									//得到图中点的数量
	size_t GetVertexNum();
	
	void ReverseTo(ALGraph &algraph);
	static ALGraph Reverse(const ALGraph &algraph);
	
	static void List2VertexNode(vector<Neuro_VertexNode> &vertexs, const Neuro_PointList &vertex_list);
	void printVertexs();
	static int GetEdgeNum(const vector<Neuro_VertexNode> &vertexs);		//得到边的数量
	int GetEdgeNum() const;							//得到边的数量
	vector<int> GetEdges(int n);						//得到某一节点的所有边的序号
	static Neuro_VertexNode ConvVertexNode(const NeuroPoint &pt);	//节点转换
	static void DelNodeEdge(Neuro_VertexNode &Node, const long long &EdgeNum);	//删除节点的边，如果EdgeNum为负，则删除所有边, 如果为正，则删掉对应节点的边
	bool isMatch(const NeuroPoint &pt, size_t &MatchNum);

	void getAllPath(const int startVertex, const int endVertex);								//找出路径
	void dumpPath();								//输出路径并保存在paths集合中
	vector<ALGraph> getPath();						//输出路径以ALGraph的形式
private:
	void lastVisitedVertexCannel();					//取消上次访问的顶点标志
	void visitInVertex(int vertex);							//将顶点加入到访问区中
	void DFS(int currentVertex, int originVertex, int destinationVertex);	//深度搜索
	void analyseBranchVertex();						//分析出分支节点
};

class fiber_collision_set
{
public:
	pair<NeuroPoint, NeuroPoint> node;	// 2×1列表，xy坐标
	pair<int, int> node_num;        // 2×1列表， first碰撞位点为纤维起始点，即第二个机器人， second碰撞位点为纤维终末点，即第一个机器人，
	pair<int, int> tree_num;        // 隶属的树，2×1列表
public:
	fiber_collision_set() {}
};

//点类
/*
class NeuroPoint
{
private:
	int x;
	int y;
	int z;
	bool empty = true;
public:
	NeuroPoint(){ empty = true; }
	NeuroPoint(const int &x, const int &y):x(x), y(y){ empty = false; }
	NeuroPoint(const int x, const int y, const int z):x(x), y(y), z(z){ empty = false; }
	~NeuroPoint(){}
	void operator= (const NeuroPoint &p2)
	{
		if (this != NULL)
		{
			this->x = p2.x;
			this->y = p2.y;
			this->z = p2.z;
		}
	};

	void operator= (const initializer_list<int> &p2)
	{
		debug::Print("void NeuroPoint::operator=(const initializer_list<int> &p2)");
		NeuroVector pt_tmp(p2);
		//this->CheckPoint(pt_tmp);
		this->x = pt_tmp.at(0);
		this->y = pt_tmp.at(1);
		if (pt_tmp.size() == 3)
		{
			this->z = pt_tmp.at(2);
		}
	};
	void SetX(const int &x) { this->x = x; }
	void SetY(const int &y) { this->y = y; }
	void SetZ(const int &z) { this->z = z; }
	bool IsEmpty() const;
	void CheckPoint(const NeuroVector &p) const;
	void print();
};
*/
/*
class NeuroVector : public vector<int>
{
protected:
	
public:
	NeuroVector() :vector() {}
	NeuroVector(const NeuroVector &v2) :vector((vector<int>)v2) {}
	NeuroVector(size_t n) :vector(n) {}
	NeuroVector(size_t n, const int &elem) :vector(n, elem) {}
	NeuroVector(initializer_list<int> &list) :vector(list) {}
	bool CheckPoint();
	void Print();
};
*/
/*
//点列表
class NeuroPtList
{
public:
	NeuroPoint *point_list;
	int size = 0;
public:
	NeuroPtList(){}
	void Init(int size);
	void Resize(int size);
	void SetPoint(NeuroPoint *pt, int num);
	void SetPoint(int x, int y, int num);
	void SetPoint(int x, int y, int z, int num);
	void print();
};
*/

#endif //__VARTYPE_H_
