#include "VarType.h"
using namespace std;
string num2str(const int num)
{
	strstream stream;
	stream << num;
	string str_tmp;
	stream >> str_tmp;
	return str_tmp;
}
string num2str(const long num)
{
	strstream stream;
	stream << num;
	string str_tmp;
	stream >> str_tmp;
	return str_tmp;
}
string num2str(const short num)
{
	strstream stream;
	stream << num;
	string str_tmp;
	stream >> str_tmp;
	return str_tmp;
}
string num2str(const double num)
{
	strstream stream;
	stream << num;
	string str_tmp;
	stream >> str_tmp;
	return str_tmp;
}
string num2str(const float num)
{
	strstream stream;
	stream << num;
	string str_tmp;
	stream >> str_tmp;
	return str_tmp;
}

int str2int(const string num)
{
	strstream stream;
	stream << num;
	int int_tmp;
	stream >> int_tmp;
	return int_tmp;
}

double str2double(const string num)
{
	strstream stream;
	stream << num;
	double double_tmp;
	stream >> double_tmp;
	return double_tmp;
}


/*
bool NeuroPoint::IsEmpty() const
{
	debug::Print("NeuroPoint::IsEmpty() const");
	return empty;
}

//检验vector数据数量是否为2或3
void NeuroPoint::CheckPoint(const NeuroVector &p) const
{
	debug::Print("bool NeuroPoint::CheckPoint(const vector<int> p) const");
	if (!p.CheckPoint)
	{
		cerr << "请检查输入的是否是点" << endl;
		exit(-1);
	}
	
}
*/
/*
bool NeuroVector::CheckPoint()
{
	debug::Print("NeuroVector::CheckPoint()");
	cout << "size: " << this->size() << endl;
	if ((this->size() < (size_t)2) || (this->size > (size_t)3))
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}

void NeuroVector::Print()
{
	debug::Print("NeuroVector::Print()被调用");
	for (NeuroVector::iterator iter = this->begin(); iter != this->end(); iter++)
	{
		cout << *iter << endl;
	}
}
*/

NeuroPoint::NeuroPoint(int x, int y):x(x), y(y)
{
}

NeuroPoint::NeuroPoint(int x, int y, int z):x(x), y(y), z(z)
{
}

NeuroPoint::NeuroPoint(const initializer_list<int> &list)
{
	if (list.size() == 2)
	{
		this->x = list.begin()[0];
		this->y = list.begin()[1];
	}
	else if (list.size() == 3)
	{
		this->x = list.begin()[0];
		this->y = list.begin()[1];
		this->z = list.begin()[2];
	}
	else
	{
		std::cerr << "初始化列表不能大于3个， 或小于2个数字" << std::endl;
		throw;
	}
	
	
}

NeuroPoint::NeuroPoint(const NeuroPoint & pt2)
{
	this->x = pt2.x;
	this->y = pt2.y;
	this->z = pt2.z;
}

NeuroPoint &NeuroPoint::operator=(const NeuroPoint & pt2)
{
	this->x = pt2.x;
	this->y = pt2.y;
	this->z = pt2.z;
	return *this;
}

void NeuroPoint::Print()const
{
	cout << "X: " << setw(10) << setiosflags(ios::left) << x << " Y: " << setw(10) << setiosflags(ios::left) << y << " Z: " << setw(10) << setiosflags(ios::left) << z << endl;
}

int * NeuroPoint::GetData()
{
	int *data = new int[3];
	data[0] = x; data[1] = y; data[2] = z;
	return data;
}

bool NeuroPoint::operator==(const NeuroPoint & p2)
{
	if ((this->x == p2.x)&&(this->y == p2.y)&&(this->z == p2.z))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NeuroPoint::operator!=(const NeuroPoint & p2)
{
	if ((this->x == p2.x)&&(this->y == p2.y)&&(this->z == p2.z))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator== (const NeuroPoint &p1, const NeuroPoint &p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!= (const NeuroPoint &p1, const NeuroPoint &p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z))
	{
		return false;
	}
	else
	{
		return true;
	}
}

NeuroPoint NeuroPoint::operator+(const int & num)
{
	NeuroPoint tmp;
	tmp.x = this->x + num;
	tmp.y = this->y + num;
	tmp.z = this->z + num;
	return tmp;
}

NeuroPoint NeuroPoint::operator-(const int & num)
{
	NeuroPoint tmp;
	tmp.x = this->x - num;
	tmp.y = this->y - num;
	tmp.z = this->z - num;
	return tmp;
}

NeuroPoint NeuroPoint::operator*(const int & num)
{
	NeuroPoint tmp;
	tmp.x = this->x * num;
	tmp.y = this->y * num;
	tmp.z = this->z * num;
	return tmp;
}

NeuroPoint NeuroPoint::operator/(const int & num)
{
	NeuroPoint tmp;
	tmp.x = this->x / num;
	tmp.y = this->y / num;
	tmp.z = this->z / num;
	return tmp;
}

NeuroPoint operator+(const NeuroPoint &pt1, const NeuroPoint &pt2)
{
	NeuroPoint pt_out;
	pt_out.x = pt1.x + pt2.x;
	pt_out.y = pt1.y + pt2.y;
	pt_out.z = pt1.z + pt2.z;
	return pt_out;
}

NeuroPoint operator-(const NeuroPoint &pt1, const NeuroPoint &pt2)
{
	NeuroPoint pt_out;
	pt_out.x = pt1.x - pt2.x;
	pt_out.y = pt1.y - pt2.y;
	pt_out.z = pt1.z - pt2.z;
	return pt_out;
}

void NeuroPoint::Clear()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}


// 浮点型NeuroPoint_d
NeuroPoint_d::NeuroPoint_d(double x, double y) :x(x), y(y)
{
}

NeuroPoint_d::NeuroPoint_d(double x, double y, double z) : x(x), y(y), z(z)
{
}

NeuroPoint_d::NeuroPoint_d(const initializer_list<double> &list)
{
	this->x = list.begin()[0];
	this->y = list.begin()[1];
	this->z = list.begin()[2];
}

NeuroPoint_d::NeuroPoint_d(const NeuroPoint_d & pt2)
{
	this->x = pt2.x;
	this->y = pt2.y;
	this->z = pt2.z;
}

NeuroPoint_d &NeuroPoint_d::operator=(const NeuroPoint_d & pt2)
{
	this->x = pt2.x;
	this->y = pt2.y;
	this->z = pt2.z;
	return *this;
}

NeuroPoint_d::NeuroPoint_d(const NeuroPoint & pt2)
{
	this->x = (double)pt2.x;
	this->y = (double)pt2.y;
	this->z = (double)pt2.z;
}

NeuroPoint_d & NeuroPoint_d::operator=(const NeuroPoint & pt2)
{
	this->x = (double)pt2.x;
	this->y = (double)pt2.y;
	this->z = (double)pt2.z;
	return *this;
}

void NeuroPoint_d::Print()const
{
	cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
}

double * NeuroPoint_d::GetData()
{
	double *data = new double[3];
	data[0] = x; data[1] = y; data[2] = z;
	return data;
}

bool NeuroPoint_d::operator==(const NeuroPoint_d & p2)
{
	if (this->x == p2.x&&this->y == p2.y&&this->z == p2.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NeuroPoint_d::operator!=(const NeuroPoint_d & p2)
{
	if (this->x == p2.x&&this->y == p2.y&&this->z == p2.z)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator== (const NeuroPoint_d &p1, const NeuroPoint_d &p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!= (const NeuroPoint_d &p1, const NeuroPoint_d &p2)
{
	if ((p1.x == p2.x) && (p1.y == p2.y) && (p1.z == p2.z))
	{
		return false;
	}
	else
	{
		return true;
	}
}

NeuroPoint_d NeuroPoint_d::operator+(const double & num)
{
	NeuroPoint_d tmp;
	tmp.x = this->x + num;
	tmp.y = this->y + num;
	tmp.z = this->z + num;
	return tmp;
}

NeuroPoint_d NeuroPoint_d::operator-(const double & num)
{
	NeuroPoint_d tmp;
	tmp.x = this->x - num;
	tmp.y = this->y - num;
	tmp.z = this->z - num;
	return tmp;
}

NeuroPoint_d NeuroPoint_d::operator*(const double & num)
{
	NeuroPoint_d tmp;
	tmp.x = this->x * num;
	tmp.y = this->y * num;
	tmp.z = this->z * num;
	return tmp;
}

NeuroPoint_d NeuroPoint_d::operator/(const double & num)
{
	NeuroPoint_d tmp;
	tmp.x = this->x / num;
	tmp.y = this->y / num;
	tmp.z = this->z / num;
	return tmp;
}

NeuroPoint_d operator+(const NeuroPoint_d &pt1, const NeuroPoint_d &pt2)
{
	NeuroPoint_d pt_out;
	pt_out.x = pt1.x + pt2.x;
	pt_out.y = pt1.y + pt2.y;
	pt_out.z = pt1.z + pt2.z;
	return pt_out;
}

NeuroPoint_d operator-(const NeuroPoint_d &pt1, const NeuroPoint_d &pt2)
{
	NeuroPoint_d pt_out;
	pt_out.x = pt1.x - pt2.x;
	pt_out.y = pt1.y - pt2.y;
	pt_out.z = pt1.z - pt2.z;
	return pt_out;
}

Neuro_PointList::Neuro_PointList()
{
	//this->list = new NeuroPoint[10000];
	//capacity_back = this->capacity = 10000;
}

Neuro_PointList::Neuro_PointList(const int & in_capacity): list(in_capacity)
{
	//this->list = new NeuroPoint[in_capacity];
	//capacity_back = this->capacity = in_capacity;
}

Neuro_PointList::Neuro_PointList(const Neuro_PointList & list2)
{
	size_t list2_size = list2.size();
	//this->list = new NeuroPoint[list2_size];
	//this->capacity = list2.capacity;
	//this->capacity_back = list2.capacity_back;
	for (size_t i = 0; i < list2_size; ++i)
	{
		this->push(list2.at_pt(i));
	}
}

Neuro_PointList & Neuro_PointList::operator=(const Neuro_PointList & list2)
{
	size_t list2_size = list2.size();
	//this->list = new NeuroPoint[list2_size];
	//this->capacity = list2.capacity;
	//this->capacity_back = list2.capacity_back;
	for (size_t i = 0; i < list2_size; ++i)
	{
		this->push(list2.at_pt(i));
	}
	return *this;
}

bool Neuro_PointList::operator<(const Neuro_PointList & list2)
{
	return this->size() < list2.size() ? true : false;
}

bool Neuro_PointList::operator>(const Neuro_PointList & list2)
{
	return this->size() > list2.size() ? true : false;
}
//Neuro_PointList::~Neuro_PointList()
//{
	//if (!list)
	//{
	//	delete[] list;
	//}
//}

size_t Neuro_PointList::size() const
{
	//return top+1;
	return this->list.size();
}

//int Neuro_PointList::Capacity()
//{
//	return capacity;
//}

void Neuro_PointList::push(const NeuroPoint &pt)
{
	/*
	if (top < (capacity - 1))
	{
		top++;
		list[top] = pt;
	}
	else
	{
		NeuroPoint *list_tmp = new NeuroPoint[capacity];
		for (int i = 0; i < 5; i++)
		{
			list_tmp[i] = list[i];
		}
		if (list != NULL)
		{
			delete[] list;
		}
		
		capacity *= 2;
		list = new NeuroPoint[capacity];
		for (int i = 0; i < (capacity / 2); i++)
		{
			list[i] = list_tmp[i];
		}
		if (!list_tmp)
		{
			delete[] list_tmp;
			list_tmp = NULL;
		}
		top++;
		list[top] = pt;
	}
	*/
	this->list.push_back(pt);
}

vector<NeuroPoint> Neuro_PointList::GetList()
{
	return list;
}

void Neuro_PointList::clear()
{
	/*
	if (!list)
	{
		delete[] list;
	}
	capacity = capacity_back;
	list = new NeuroPoint[capacity];
	top = -1;
	*/
	this->list.clear();
}

NeuroPoint Neuro_PointList::pop()
{
	/*
	if (top > -1)
	{
		top--;
		return list[top + 1];
	}
	else
	{
		cerr << "堆栈已空" << endl;
		exit(-1);
	}
	*/
	NeuroPoint pt = this->list.back();
	this->list.pop_back();
	return pt;
}

bool Neuro_PointList::isMatch(const NeuroPoint & pt)
{
	bool tmp = false;
	size_t list_size = this->size();
	for (int i = 0; i <= list_size; i++)
	{
		if (this->list.at(i) == pt)
			tmp = true;
	}
	return tmp;
}

void Neuro_PointList::PrintInfo()
{
	std::cout << "list信息：" << std::endl;
	std::cout << "Size: " << this->list.size() << std::endl;
	//cout << "capacity: " << capacity << endl;
	//cout << "capacity_back: " << capacity_back << endl;
	//cout << "*****************" << endl;
}

void Neuro_PointList::PrintPt()
{
	size_t top = this->list.size();
	for (size_t i = 0; i < top; i++)
	{
		cout << "[" << i << "] " << list.at(i).x<< " " << list.at(i).y << " " << list.at(i).z << endl;
	}
}

//返回从0开始计算的第n个点，返回int数组
NeuroPoint &Neuro_PointList::at(const int & n)
{
	//int *pt = NULL;
	//pt = list[n].GetData();
	return this->list.at(n);
}

NeuroPoint Neuro_PointList::at_pt(const size_t & n) const
{
	return this->list.at(n);
}

//返回从0开始计算的第n个点，返回NeuroPoint数据类型
NeuroPoint Neuro_PointList::at_pt(const int & n) const
{
	return this->list.at(n);
}

NeuroPoint Neuro_PointList::at_pt(const long long & n) const
{
	return this->list.at(n);
}

bool Neuro_PointList::isEmpty()
{
	if (!this->size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Move the number of edges of vertex. The number will be added by move_num.
void ALGraph::MoveEdgeNum(Neuro_VertexNode& vertex, const size_t &move_num)
{
	debug::Print("void ALGraph::MoveEdgeNum(Neuro_VertexNode& vertex, const int &move_num)被调用");
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;
	if (NULL != vertex.firstedge)
	{
		pter = vertex.firstedge;
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = pter->adjvertex + move_num;
		vertex.firstedge = pNew;
		pLas = pNew;
		while (NULL != pter->next)
		{
			pter = pter->next;
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = pter->adjvertex + move_num;
			pLas->next = pNew;
			pLas = pNew;
		}
	}
}

ALGraph::ALGraph()
{
	debug::Print("ALGraph::ALGraph()被调用");
	this->pathNum = 0;

}

ALGraph::~ALGraph()
{
	debug::Print("ALGraph::~ALGraph()被调用");
    vector<Neuro_VertexNode>::iterator iter;
	for (iter = this->vertexs.begin(); iter != this->vertexs.end(); ++iter)
	{
		ALGraph::DelNodeEdge(*iter, -1);
	}
}

ALGraph::ALGraph(const ALGraph & algraph2)
{
	debug::Print("ALGraph::ALGraph(const ALGraph & algraph2)被调用");
	//清理
	if (this->GetSize())
	{
		vector<Neuro_VertexNode>::iterator iter;
		for (iter = this->vertexs.begin(); iter != this->vertexs.end(); ++iter)
		{
			ALGraph::DelNodeEdge(*iter, -1);
		}
	}
	//复制顶点
	this->vertexs = algraph2.vertexs;
	this->BFSsequence = algraph2.BFSsequence;
	this->visitedVertex = algraph2.visitedVertex;
	this->originVertex = algraph2.originVertex;
	this->pathNum = algraph2.pathNum;
	this->tree = algraph2.tree;
	//复制边
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;
	for (int i = 0; i < algraph2.GetSize(); ++i)
	{
		if (NULL != algraph2.vertexs.at(i).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pter = algraph2.vertexs.at(i).firstedge;
			pNew->adjvertex = pter->adjvertex;
			this->vertexs.at(i).firstedge = pNew;
			pLas = pNew;
			pNew = NULL;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = pter->adjvertex;
				pLas->next = pNew;
				pLas = pNew;
				pNew = NULL;
			}
			if (NULL != pter)
			{
				pter = NULL;
			}
			if (NULL != pNew)
			{
				pNew = NULL;
			}
			if (NULL != pLas)
			{
				pLas = NULL;
			}
		}
		else
		{
			this->vertexs.at(i).firstedge = NULL;
		}
	}
}

ALGraph & ALGraph::operator=(const ALGraph & algraph2)
{
	debug::Print("ALGraph::ALGraph(const ALGraph & algraph2)被调用");
	//清理
	if (this->GetSize())
	{
		vector<Neuro_VertexNode>::iterator iter;
		for (iter = this->vertexs.begin(); iter != this->vertexs.end(); ++iter)
		{
			ALGraph::DelNodeEdge(*iter, -1);
		}
	}
	//复制顶点
	this->vertexs = algraph2.vertexs;
	this->BFSsequence = algraph2.BFSsequence;
	this->visitedVertex = algraph2.visitedVertex;
	this->originVertex = algraph2.originVertex;
	this->pathNum = algraph2.pathNum;
	this->tree = algraph2.tree;
	//复制边
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;
	for (int i = 0; i < algraph2.GetSize(); ++i)
	{
		if (NULL != algraph2.vertexs.at(i).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pter = algraph2.vertexs.at(i).firstedge;
			pNew->adjvertex = pter->adjvertex;
			this->vertexs.at(i).firstedge = pNew;
			pLas = pNew;
			pNew = NULL;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = pter->adjvertex;
				pLas->next = pNew;
				pLas = pNew;
				pNew = NULL;
			}
			if (NULL != pter)
			{
				pter = NULL;
			}
			if (NULL != pNew)
			{
				pNew = NULL;
			}
			if (NULL != pLas)
			{
				pLas = NULL;
			}
		}
		else
		{
			this->vertexs.at(i).firstedge = NULL;
		}
	}
	return *this;
}

// 建立图的存储矩阵成员函数
// vertex_list储存节点坐标，edge_list储存节点之间的连接信息
// edge_list 参数输入形式为[x, y; i, j] x与y相连
void ALGraph::CreateGraph(const Neuro_PointList & vertex_list, const pair<vector<int>, vector<int>>& edge_list)
{
	debug::Print("void ALGraph::CreateGraph(const Neuro_PointList & vertex_list, const pair<vector<int>, vector<int>>& edge_list)调用");
	List2VertexNode(this->vertexs, vertex_list);
	//建立节点连接信息
	int p1 = -1, p2 = -1;
	Neuro_EdgeNode *pter=NULL, *rter=NULL;
	bool match = false;
	size_t edge_num = edge_list.first.size();
	for (size_t i = 0; i < edge_num; ++i)
	{
		p1 = edge_list.first[i];
		p2 = edge_list.second[i];
		if ((p1 >= this->GetSize()) || (p2 >= this->GetSize()))
		{
			cerr << "连接序号大于顶点序号" << endl;
			throw;
		}
		//正向连接
		if (this->vertexs[p1].firstedge == NULL)
		{
			rter = new Neuro_EdgeNode;
			rter->adjvertex = p2;
			this->vertexs[p1].firstedge = rter;
			rter = NULL;
		}
		else
		{
			pter = this->vertexs[p1].firstedge;
			if (p2 == pter->adjvertex)
			{
				match = true;
			}
			while (pter->next != NULL)
			{
				if (p2 == pter->adjvertex)
				{
					match = true;
				}
				pter = pter->next;
			}
			if (!match)
			{
				rter = new Neuro_EdgeNode;
				rter->adjvertex = p2;
				pter->next = rter;
			}
			pter = NULL;
			rter = NULL;
			match = false;
		}

		//反向连接
		if (this->vertexs[p2].firstedge == NULL)
		{
			rter = new Neuro_EdgeNode;
			rter->adjvertex = p1;
			this->vertexs[p2].firstedge = rter;
			rter = NULL;
		}
		else
		{
			pter = this->vertexs[p2].firstedge;
			if (p1 == pter->adjvertex)
			{
				match = true;
			}
			while (pter->next != NULL)
			{
				if (p1 == pter->adjvertex)
				{
					match = true;
				}
				pter = pter->next;
			}
			if (!match)
			{
				rter = new Neuro_EdgeNode;
				rter->adjvertex = p1;
				pter->next = rter;
			}
			pter = NULL;
			rter = NULL;
			match = false;
		}
	}

}

void ALGraph::CreateGraph(const vector<Neuro_VertexNode>& vertex_list)
{
	debug::Print("void ALGraph::CreateGraph(const vector<Neuro_VertexNode>& vertex_list)被调用");
	auto vertex_list_size = vertex_list.size();
	if (!vertex_list_size)
	{
		return;
	}
	for (size_t i = 0; i < vertex_list_size; ++i)
	{
		this->vertexs.push_back(vertex_list.at(i));
	}
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;
	for (int i = 0; i < this->GetSize(); ++i)
	{
		if (NULL != vertexs.at(i).firstedge)
		{
			pter = vertexs.at(i).firstedge;
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = pter->adjvertex;
			vertexs.at(i).firstedge = pNew;
			pLas = pNew;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = pter->adjvertex;
				pLas->next = pNew;
				pLas = pNew;

			}
		}
	}
}

void ALGraph::AddVertex(const NeuroPoint &vertex)
{
	Neuro_VertexNode vertex_node;
	vertex_node.vertex = vertex;
	this->vertexs.push_back(vertex_node);
}

//添加一个点及其连接信息 connect_point应为在vertexs中的顶点
void ALGraph::AddVertex(const NeuroPoint &vertex, const size_t &connect_point)
{
	Neuro_VertexNode vertex_node;
	vertex_node.vertex = vertex;
	this->vertexs.push_back(vertex_node);
	size_t vertex_node_num = this->vertexs.size() - 1; //最后一个节点的下标
	Neuro_EdgeNode *pVertex = NULL, *pNewNode = NULL;
	//建立输入点的链接关系
	pNewNode = new Neuro_EdgeNode;
	pNewNode->adjvertex = connect_point;
    vertexs.at(vertex_node_num).n = pNewNode;
	pNewNode = NULL;
	//建立连接点的连接关系
	pNewNode = new Neuro_EdgeNode;
	pNewNode->adjvertex = vertex_node_num;
	if (this->vertexs.at(connect_point).firstedge != NULL)
	{
		pVertex = vertexs.at(connect_point).firstedge;
		while (pVertex->next != NULL)
		{
			pVertex = pVertex->next;
		}
		pVertex->next = pNewNode;
	}
	else
	{
		this->vertexs.at(connect_point).firstedge = pNewNode;
	}
	pNewNode = NULL;

}

// 添加点列表及其连接信息
// vertex_list: 顶点列表
// connect_point: 连接原表点的下标
// dir: 连接方向， 0：连接位点为第一个节点, 第二个机器人，1：连接位点为最后一个节点， 第一个机器人 
void ALGraph::AddVertexList(const vector<Neuro_VertexNode>& vertex_list, const size_t & connect_point, const bool & dir)
{
	debug::Print("void ALGraph::AddVertexList(const vector<Neuro_VertexNode>& vertex_list, const int & connect_point, const bool & dir)被调用");
	size_t index_first = this->GetSize();								//vertex_list中第一个点在原表中的下标
	size_t index_last = this->GetSize() + vertex_list.size() - 1;		//vertex_list中最后一个点在原表中的下标
	Neuro_EdgeNode *pter = NULL, *pNew = NULL;
	for (int i = 0; i < vertex_list.size(); ++i)
	{
		this->vertexs.push_back(vertex_list.at(i));
		ALGraph::MoveEdgeNum(this->vertexs.back(), index_first);
	}
	if (!dir)
	{
		if (NULL == this->vertexs.at(connect_point).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_first;
			this->vertexs.at(connect_point).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(connect_point).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_first;
			pter->next = pNew;
		}

		if (NULL == this->vertexs.at(index_first).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			this->vertexs.at(index_first).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(index_first).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			pter->next = pNew;
		}
	}
	else
	{
		if (this->vertexs.at(connect_point).firstedge == NULL)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_last;
			this->vertexs.at(connect_point).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(connect_point).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_last;
			pter->next = pNew;
		}

		if (NULL == this->vertexs.at(index_last).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			this->vertexs.at(index_last).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(index_last).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			pter->next = pNew;
		}
	}
}

void ALGraph::AddVertexList(const vector<Neuro_VertexNode>& vertex_list, const size_t & connect_point1, const size_t & connect_point2)
{
	debug::Print("void ALGraph::AddVertexList(const vector<Neuro_VertexNode>& vertex_list, const size_t & connect_point1, const size_t & connect_point2)被调用");
	size_t index_first = this->GetSize();								//vertex_list中第一个点在原表中的下标
	size_t index_last = this->GetSize() + vertex_list.size() - 1;		//vertex_list中最后一个点在原表中的下标
	Neuro_EdgeNode *pter = NULL, *pNew = NULL;
	for (int i = 0; i < vertex_list.size(); ++i)
	{
		this->vertexs.push_back(vertex_list.at(i));
		ALGraph::MoveEdgeNum(this->vertexs.back(), index_first);
	}
	size_t connect_point2_new = connect_point2 + index_first - 1;		// connect_point2原表中的下标
	if (NULL == this->vertexs.at(connect_point1).firstedge)
	{
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point2_new;
		this->vertexs.at(connect_point1).firstedge = pNew;
	}
	else
	{
		pter = this->vertexs.at(connect_point1).firstedge;
		while (pter->next != NULL)
		{
			pter = pter->next;
		}
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point2_new;
		pter->next = pNew;
	}

	if (NULL == this->vertexs.at(connect_point2_new).firstedge)
	{
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point1;
		this->vertexs.at(connect_point2_new).firstedge = pNew;
	}
	else
	{
		pter = this->vertexs.at(connect_point2_new).firstedge;
		while (pter->next != NULL)
		{
			pter = pter->next;
		}
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point1;
		pter->next = pNew;
	}
}

// 添加点列表及其连接信息
// Graph: 顶点列表
// connect_point: 连接原表点的下标
// dir: 连接方向， 0：连接位点为第一个节点, 第二个机器人，1：连接位点为最后一个节点， 第一个机器人 
void ALGraph::AddVertexList(const ALGraph & Graph, const size_t & connect_point, const bool & dir)
{
	debug::Print("void ALGraph::AddVertexList(const ALGraph & Graph, const size_t & connect_point, const bool & dir)被调用");
	if (!Graph.GetSize())
	{
		return;
	}
	size_t index_first = this->GetSize();								//Graph中第一个点在原表中的下标
	size_t index_last = this->GetSize() + Graph.GetSize() - 1;		//Graph中最后一个点在原表中的下标
	Neuro_EdgeNode *pter = NULL, *pNew = NULL;
	for (int i = 0; i < Graph.GetSize(); ++i)
	{
		this->vertexs.push_back(Graph.vertexs.at(i));
		ALGraph::MoveEdgeNum(this->vertexs.back(), index_first);
	}
	if (!dir)
	{
		if (NULL == this->vertexs.at(connect_point).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_first;
			this->vertexs.at(connect_point).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(connect_point).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_first;
			pter->next = pNew;
		}

		if (NULL == this->vertexs.at(index_first).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			this->vertexs.at(index_first).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(index_first).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			pter->next = pNew;
		}
	}
	else
	{
		if (this->vertexs.at(connect_point).firstedge == NULL)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_last;
			this->vertexs.at(connect_point).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(connect_point).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = index_last;
			pter->next = pNew;
		}

		if (NULL == this->vertexs.at(index_last).firstedge)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			this->vertexs.at(index_last).firstedge = pNew;
		}
		else
		{
			pter = this->vertexs.at(index_last).firstedge;
			while (pter->next != NULL)
			{
				pter = pter->next;
			}
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point;
			pter->next = pNew;
		}
	}
}

//connect_point1: this的连接点序号
//connect_point2: 新加纤维Graph的连接点序号
void ALGraph::AddVertexList(const ALGraph & Graph, const size_t & connect_point1, const size_t & connect_point2)
{
	debug::Print("void ALGraph::AddVertexList(const ALGraph & Graph, const size_t & connect_point1, const size_t & connect_point2)被调用");
	size_t index_first = this->GetSize();								//vertex_list中第一个点在原表中的下标
	size_t index_last = this->GetSize() + Graph.GetSize() - 1;		//vertex_list中最后一个点在原表中的下标
	Neuro_EdgeNode *pter = NULL, *pNew = NULL;
	for (int i = 0; i < Graph.GetSize(); ++i)
	{
		this->vertexs.push_back(Graph.vertexs.at(i));
		ALGraph::MoveEdgeNum(this->vertexs.back(), index_first);
	}
	size_t connect_point2_new = connect_point2 + index_first;		// connect_point2原表中的下标
	if (NULL == this->vertexs.at(connect_point1).firstedge)
	{
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point2_new;
		this->vertexs.at(connect_point1).firstedge = pNew;
	}
	else
	{
		pter = this->vertexs.at(connect_point1).firstedge;
		while (pter->next != NULL)
		{
			pter = pter->next;
		}
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point2_new;
		pter->next = pNew;
	}

	if (NULL == this->vertexs.at(connect_point2_new).firstedge)
	{
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point1;
		this->vertexs.at(connect_point2_new).firstedge = pNew;
	}
	else
	{
		pter = this->vertexs.at(connect_point2_new).firstedge;
		while (pter->next != NULL)
		{
			pter = pter->next;
		}
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point1;
		pter->next = pNew;
	}
}

//纤维内部两个点之间建立连接关系
void ALGraph::AddConnect(const size_t & connect_point1, const size_t & connect_point2)
{
	Neuro_EdgeNode *pter = NULL, *pNew = NULL;
	bool bIsMatch = false;
	if (this->vertexs.at(connect_point1).firstedge == NULL)
	{
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point2;
		this->vertexs.at(connect_point1).firstedge = pNew;
		pNew = NULL;
	}
	else
	{
		pter = this->vertexs.at(connect_point1).firstedge;
		if (connect_point2 == pter->adjvertex) bIsMatch = true;
		while (NULL != pter->next)
		{
			pter = pter->next;
			if (connect_point2 == pter->adjvertex) bIsMatch = true;
		}
		if (!bIsMatch)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point2;
			pter->next = pNew;
			pNew = NULL;
		}
		pter = NULL;
	}

	if (this->vertexs.at(connect_point2).firstedge == NULL)
	{
		pNew = new Neuro_EdgeNode;
		pNew->adjvertex = connect_point1;
		this->vertexs.at(connect_point2).firstedge = pNew;
		pNew = NULL;
	}
	else
	{
		pter = this->vertexs.at(connect_point2).firstedge;
		if (connect_point1 == pter->adjvertex) bIsMatch = true;
		while (NULL != pter->next)
		{
			pter = pter->next;
			if (connect_point1 == pter->adjvertex) bIsMatch = true;
		}
		if (!bIsMatch)
		{
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = connect_point1;
			pter->next = pNew;
			pNew = NULL;
		}
		pter = NULL;
	}
}
	
//将Neuro_PointList转换为vector<Neuro_VertexNode>
void ALGraph::List2VertexNode(vector<Neuro_VertexNode> &vertexs, const Neuro_PointList & vertex_list)
{
	debug::Print("void ALGraph::List2VertexNode(vector<Neuro_VertexNode> &vertexs, const Neuro_PointList & vertex_list)调用");
	size_t ListSize = vertex_list.size();
	Neuro_VertexNode vertexTmp;
	for (size_t i = 0; i < ListSize; ++i)
	{
		vertexTmp.vertex = vertex_list.at_pt(i);
		vertexs.push_back(vertexTmp);
	}
	
}

void ALGraph::printVertexs()
{
	debug::Print("void ALGraph::printVertexs()调用");
	vector<Neuro_VertexNode>::iterator iter;
	Neuro_EdgeNode *pter = NULL;
	int count = 0;
	for (iter = this->vertexs.begin(); iter != this->vertexs.end(); ++iter)
	{
		cout << "[" << count << "] ";
        ++count;
		iter->vertex.Print();
		cout << "连接点序号：";
		pter = iter->firstedge;
		int count = 0;
		while (NULL != pter)
		{
			cout << pter->adjvertex << ", ";
			pter = pter->next;
		}
		pter = NULL;
		cout << endl;
	}
}

void ALGraph::Clear()
{
	debug::Print("void ALGraph::Clear()被调用");
	vector<Neuro_VertexNode>::iterator iter;
	for (iter = this->vertexs.begin(); iter != this->vertexs.end(); ++iter)
	{
		ALGraph::DelNodeEdge(*iter, -1);
	}
	this->vertexs.clear();
	this->pathNum = 0;
	this->visited.clear();
}

Neuro_VertexNode ALGraph::Pop()
{
	if (!this->GetSize())
	{
		cerr << "ALGraph::data 已空" << endl;
		throw;
	}
	size_t node_num = this->GetSize() - 1;
	Neuro_VertexNode Vertex = this->vertexs.back();
	this->vertexs.pop_back();
	Neuro_EdgeNode *pter = NULL, *pDel = NULL, *pLas = NULL;
	if (NULL != Vertex.firstedge)
	{
		pter = Vertex.firstedge;
		pLas = pter;
		ALGraph::DelNodeEdge(this->at(pter->adjvertex), node_num);
		while (NULL != pter->next)
		{
			pter = pter->next;
			ALGraph::DelNodeEdge(this->at(pter->adjvertex), node_num);
		}
	}
	ALGraph::DelNodeEdge(Vertex, -1);
	return Vertex;
}

size_t ALGraph::GetSize() const
{
	return this->vertexs.size();
}

size_t ALGraph::GetVertexNum()
{
	return this->vertexs.size();
}

vector<int> ALGraph::GetEdges(int n)
{
	vector<int> ret;
	Neuro_EdgeNode *pter = NULL;
	if (this->at(n).firstedge != NULL)
	{
		pter = this->at(n).firstedge;
		ret.push_back((int)pter->adjvertex);
		while (pter->next != NULL)
		{
			pter = pter->next;
			ret.push_back((int)pter->adjvertex);
		}
	}
	return ret;
}
/*
vector<Neuro_VertexNode> ALGraph::Reverse(const vector<Neuro_VertexNode> &vertex_list)
{
	debug::Print("vector<Neuro_VertexNode> ALGraph::Reverse(const vector<Neuro_VertexNode> &vertex_list)被调用");
	// 反转顶点节点序号
	vector<Neuro_VertexNode> vertex_reversed;
	for (size_t i = (vertex_list.size() - 1); i > 0; --i)
	{
		vertex_reversed.push_back(vertex_list.at(i));
	}
	vertex_reversed.push_back(vertex_list.at(0));
	// 反转表节点序号
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;
	for (size_t i = 0; i < vertex_reversed.size(); ++i)
	{
		if (NULL != vertex_reversed.at(i).firstedge)
		{
			pter = vertex_reversed.at(i).firstedge;
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = vertex_reversed.size() - pter->adjvertex - 1;
			vertex_reversed.at(i).firstedge = pNew;
			pLas = pNew;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = vertex_reversed.size() - pter->adjvertex - 1;
				pLas->next = pNew;
				pLas = pLas->next;
			}
		}
	}
	pter = NULL, pNew = NULL, pLas = NULL;
	return vertex_reversed;
}
*/
void ALGraph::ReverseTo(ALGraph & algraph)
{
	debug::Print("ALGraph ALGraph::ReverseTo(const ALGraph & algraph)被调用");
	if (!this->GetSize())
	{
		algraph = ALGraph();
		return;
	}

	size_t vertexs_size = this->vertexs.size() - 1;
	for (size_t i = vertexs_size; i > 0; i--)
	{
		algraph.vertexs.push_back(this->vertexs.at(i));
	}
	algraph.vertexs.push_back(this->vertexs.at(0));
	// 反转表节点序号
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;

	vertexs_size = algraph.vertexs.size();
	for (size_t i = 0; i < vertexs_size; ++i)
	{
		if (NULL != algraph.vertexs.at(i).firstedge)
		{
			pter = algraph.vertexs.at(i).firstedge;
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = algraph.vertexs.size() - pter->adjvertex - 1;
			algraph.vertexs.at(i).firstedge = pNew;
			pLas = pNew;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = algraph.vertexs.size() - pter->adjvertex - 1;
				pLas->next = pNew;
				pLas = pLas->next;
			}
		}
	}
	pter = NULL, pNew = NULL, pLas = NULL;
}

ALGraph ALGraph::Reverse(const ALGraph & algraph)
{
	debug::Print("ALGraph ALGraph::Reverse(const ALGraph & algraph)被调用");
	ALGraph reversed;
	size_t vertexs_size = algraph.vertexs.size() - 1;
	for (size_t i = vertexs_size; i > 0; i--)
	{
		reversed.vertexs.push_back(algraph.vertexs.at(i));
	}
	reversed.vertexs.push_back(algraph.vertexs.at(0));
	// 反转表节点序号
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;

	vertexs_size = reversed.vertexs.size();
	for (size_t i = 0; i < vertexs_size; ++i)
	{
		if (NULL != reversed.vertexs.at(i).firstedge)
		{
			pter = reversed.vertexs.at(i).firstedge;
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = reversed.vertexs.size() - pter->adjvertex - 1;
			reversed.vertexs.at(i).firstedge = pNew;
			pLas = pNew;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = reversed.vertexs.size() - pter->adjvertex - 1;
				pLas->next = pNew;
				pLas = pLas->next;
			}
		}
	}
	pter = NULL, pNew = NULL, pLas = NULL;
	return reversed;
}

/*
vector<Neuro_VertexNode> ALGraph::Reverse() const
{
	debug::Print("vector<Neuro_VertexNode> ALGraph::Reverse() const被调用");
	// 反转顶点节点序号
	vector<Neuro_VertexNode> vertex_reversed;
	size_t vertexs_size = this->vertexs.size() - 1;
	for (size_t i = vertexs_size; i > 0; i--)
	{
		vertex_reversed.push_back(this->vertexs.at(i));
	}
	vertex_reversed.push_back(this->vertexs.at(0));
	// 反转表节点序号
	Neuro_EdgeNode *pter = NULL, *pNew = NULL, *pLas = NULL;
	for (size_t i = 0; i < vertex_reversed.size(); ++i)
	{
		if (NULL != vertex_reversed.at(i).firstedge)
		{
			pter = vertex_reversed.at(i).firstedge;
			pNew = new Neuro_EdgeNode;
			pNew->adjvertex = vertex_reversed.size() - pter->adjvertex - 1;
			vertex_reversed.at(i).firstedge = pNew;
			pLas = pNew;
			while (NULL != pter->next)
			{
				pter = pter->next;
				pNew = new Neuro_EdgeNode;
				pNew->adjvertex = vertex_reversed.size() - pter->adjvertex - 1;
				pLas->next = pNew;
				pLas = pLas->next;
			}
		}
	}
	pter = NULL, pNew = NULL, pLas = NULL;
	return vertex_reversed;
}
*/
//得到边的数量
int ALGraph::GetEdgeNum(const vector<Neuro_VertexNode> &vertexs)
{
	size_t vertex_num = vertexs.size();
	int edge_num = 0;
	Neuro_EdgeNode *pter;		//扫描用指针
	for (int i = 0; i < vertex_num; ++i)
	{
		if (vertexs.at(i).firstedge != NULL)
		{
			++edge_num;
			pter = vertexs.at(i).firstedge;
			while (pter->next != NULL)
			{
				++edge_num;
				pter = pter->next;
			}
		}
	}
	return edge_num;
}

//得到边的数量
int ALGraph::GetEdgeNum() const
{
	return ALGraph::GetEdgeNum(this->vertexs);
}



vector<Neuro_VertexNode> &ALGraph::GetData()
{
	return this->vertexs;
}

Neuro_PointList ALGraph::GetPointList()
{
	Neuro_PointList list;
	size_t PtSize = this->GetSize();
	for (size_t i = 0; i < PtSize; ++i)
	{
		list.push(this->at(i).vertex);
	}
	return list;
}

Neuro_VertexNode &ALGraph::at(const size_t &n)
{
	return this->vertexs.at(n);
}

NeuroPoint ALGraph::GetPoint(const size_t & n)const
{
	NeuroPoint pt = this->vertexs.at(n).vertex;
	return pt;
}

//节点转换
Neuro_VertexNode ALGraph::ConvVertexNode(const NeuroPoint &pt)
{
	Neuro_VertexNode node;
	node.vertex = pt;
	return node;
}

//删除节点的边，如果EdgeNum为负，则删除所有边, 如果为正，则删掉对应节点的边
void ALGraph::DelNodeEdge(Neuro_VertexNode &Node, const long long &EdgeNum)
{
	Neuro_EdgeNode *pter = NULL, *pLas = NULL, *pDel = NULL;
	if (0 > EdgeNum)
	{
		if (NULL != Node.firstedge)
		{
			pter = Node.firstedge;
			pLas = pter;
			while (NULL != pter->next)
			{
				pter = pter->next;
				if (NULL != pLas)
				{
					delete pLas;
					pLas = NULL;
				}
				pLas = pter;
			}
			if (NULL != pter)
			{
				delete pter;
				pter = NULL;
				pLas = NULL;
			}
			if (NULL != Node.firstedge)
			{
				Node.firstedge = NULL;
			}
		}
		
	}
	else
	{
		if (NULL != Node.firstedge)
		{
			pter = Node.firstedge;
			pLas = pter;
			if (EdgeNum == pter->adjvertex)
			{
				pDel = pter;
				if (NULL != pter->next)
				{
					pter = pter->next;
					delete pDel;
					pDel = NULL; pLas = NULL;
					Node.firstedge = pter;
				}
				else
				{
					delete pDel;
					pDel = NULL; pLas = NULL; pter = NULL;
					Node.firstedge = NULL;
				}
			}
			while ((NULL != pter)&&(NULL != pter->next))
			{
				pter = pter->next;
				if (EdgeNum == pter->adjvertex)
				{
					if (NULL != pter->next)
					{
						pDel = pter;
						pter = pter->next;
						delete pDel; pDel = NULL;
						pLas->next = pter;
					}
					else
					{
						delete pter; pter = NULL;
						pLas->next = NULL;
					}
				}
				else
				{
					pLas = pter;
				}
			}
		}
		
	}
}

bool ALGraph::isMatch(const NeuroPoint & pt, size_t & MatchNum)
{
	auto dataSize = this->GetSize();
	for (size_t i = 0; i < dataSize; ++i)
	{
		if (pt == this->vertexs.at(i).vertex)
		{
			MatchNum = i;
			return true;
		}
	}
	return false;
}

/*
author:chegde@foxmail.com
找到两个节点的所有通路并储存在ALGraph的paths中
*/
void ALGraph::getAllPath(const int startVertex, const int endVertex)
{
	//如果需要躲避分支节点则启用下行语句
	//this->analyseBranchVertex();

	this->DFS(startVertex, startVertex, endVertex);

}

/*
author:chegde@foxmail.com
输出并储存所有通路
*/
void ALGraph::dumpPath()
{
	pathNum = pathNum + 1;
	cout << "第" << pathNum << "条路径" << endl;
	vector<int>::iterator it;
	for (it = visited.begin(); it != visited.end(); it++) {
		cout << *it << "  ";
	}
	this->paths.push_back(visited);

	cout << endl;

}

/*
author:chegde@foxmail.com
输出通路以ALGraph的方式
*/
vector<ALGraph> ALGraph::getPath()
{
	vector<ALGraph> ans;
	vector<vector<int>>::iterator whichPath;
	//第几条通路
	vector<int>::iterator eachVertexSubscriptInOnePath;
	//每个通路中的节点下标
	for (whichPath = paths.begin(); whichPath != paths.end(); whichPath++) {
		ALGraph createOneALGraph;
		//复制节点结构
		Neuro_PointList nowALGraphPoinList = this->GetPointList();
		vector<int> pairStartInPath(*whichPath);
		vector<int> pairEndInPath(*whichPath);

		//删除开头
		pairStartInPath.erase(pairStartInPath.begin());
		//删除结尾
		pairEndInPath.pop_back();


		pair<vector<int>, vector<int> > arc;
		arc.first = pairStartInPath;
		arc.second = pairEndInPath;

		createOneALGraph.CreateGraph(nowALGraphPoinList, arc);
		//完成一个通路性质的ALGraph

		ans.push_back(createOneALGraph);
	}
	return ans;
}

/*
author:chegde@foxmail.com
跳回上一节点
*/
void ALGraph::lastVisitedVertexCannel()
{
	this->vertexs.at(this->visited.back()).pathVisited = false;
	this->visited.pop_back();
}

/*
author:chegde@foxmail.com
访问该节点并把该节点标记在尝试路径中
*/
void ALGraph::visitInVertex(int vertex)
{
	this->vertexs.at(vertex).pathVisited = true;
	this->visited.push_back(vertex);
}

/*
author:chegde@foxmail.com
深度搜索
*/
void ALGraph::DFS(int currentVertex, int originVertex, int destinationVertex)
{
	//找到当前点所能到达 Neuro_EdgeNode 已经是所有能到达

	//让该点已经被访问
	visitInVertex(currentVertex);

	//如果 该点是目的地 则输出路径
	if (currentVertex == destinationVertex) {
		this->dumpPath();
	}
	//如果 不是分支节点 或者 还在起点 该语句为了不走分支节点
	if (this->vertexs.at(currentVertex).isBranchVertex == false || currentVertex == originVertex) {
		// 每条路尝试一次

		Neuro_EdgeNode *toNode = NULL;	//遍历到达
		toNode = this->vertexs.at(currentVertex).firstedge;
		while (toNode != NULL) {
			//如果可以到
			if (this->vertexs.at(toNode->adjvertex).pathVisited == false) {
				//dfs一下
				this->DFS(toNode->adjvertex, originVertex, destinationVertex);
			}
			toNode = toNode->next;
		}
	}

	//取消上一步访问
	lastVisitedVertexCannel();


}

/*
author:chegde@foxmail.com
分析出分支节点
*/
void ALGraph::analyseBranchVertex()
{

	Neuro_EdgeNode *currentNodeToNewNode = NULL;	//边表头指针
	vector<Neuro_VertexNode>::iterator node;
	for (node = this->vertexs.begin(); node != this->vertexs.end(); node++) {
		int count = 0;
		currentNodeToNewNode = node->firstedge;
		while (currentNodeToNewNode != NULL) {
			currentNodeToNewNode = currentNodeToNewNode->next;
			count++;
		}
		if (count > 2) {
			node->isBranchVertex = true;
		}
	}
}

void Neuro_VertexNode::print() const
{
	cout << "顶点序号为：";
	this->vertex.Print();
	Neuro_EdgeNode *pter = NULL;
	cout << "连接点序号为：";
	if (NULL != this->firstedge)
	{
		pter = this->firstedge;
		cout << pter->adjvertex << ", ";
		while (NULL != pter->next)
		{
			pter = pter->next;
			cout << pter->adjvertex << ", ";
		}
	}
	pter = NULL;
	
}

int &RectSharp::at(const int &n)
{
	switch (n)
	{
	case 0:
		return data.first.first;
		break;
	case 1:
		return data.first.second;
		break;
	case 2:
		return data.second.first;
		break;
	case 3:
		return data.second.second;
		break;
	default:
		cerr << "out of range" << endl;
		throw out_of_range("下标越界");
	}
}
bool RectSharp::isIn(const NeuroPoint &pt)const
{
	if (pt.x >= this->x() && pt.y >= this->y() && pt.x <= this->RightDownX() && pt.y <= this->RightDownY())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int RectSharp::x() const
{
	return data.first.first;
}

int RectSharp::y() const
{
	return data.first.second;
}

int RectSharp::w() const
{
	return data.second.first;
}

int RectSharp::h() const
{
	return data.second.second;
}

int RectSharp::RightDownX() const
{
	return data.first.first + data.second.first - 1;
}

int RectSharp::RightDownY() const
{
	return data.first.second + data.second.second - 1;
}

void RectSharp::print()const
{
	cout << "X: " << data.first.first << " Y: " << data.first.second << " Width: " << data.second.first << " Height: " << data.second.second << endl;
}

ImSize::ImSize(initializer_list<int> size)
{
	rows = size.begin()[0];
	cols = size.begin()[1];
	if (size.size() >= 3)
	{
		layers = size.begin()[2];
	}
}

void ImSize::print() const
{
	cout << "Rows: " << rows << " cols: " << cols << " layers: " << layers << endl;
}

Neuro_PtList_linked::Neuro_PtList_linked(const int & in_capacity):data(in_capacity)
{
}

Neuro_PtList_linked::Neuro_PtList_linked(const Neuro_PtList_linked & list2)
{
	for (auto iter = list2.data.begin(); iter != list2.data.end(); ++iter)
	{
		this->data.push_back(*iter);
	}
}

Neuro_PtList_linked & Neuro_PtList_linked::operator=(const Neuro_PtList_linked & list2)
{
	for (auto iter = list2.data.begin(); iter != list2.data.end(); ++iter)
	{
		this->data.push_back(*iter);
	}
	return *this;
}

size_t Neuro_PtList_linked::size() const
{
	return this->data.size();
}

void Neuro_PtList_linked::push(const NeuroPoint & pt)
{
	this->data.push_back(pt);
}

list<NeuroPoint> Neuro_PtList_linked::GetList()
{
	return data;
}

void Neuro_PtList_linked::clear()
{
	data.clear();
}

NeuroPoint Neuro_PtList_linked::pop()
{
	NeuroPoint pt = this->data.back();
	data.pop_back();
	return pt;
}

bool Neuro_PtList_linked::isMatch(const NeuroPoint & pt)
{
	for (auto iter = this->data.begin(); iter != this->data.end(); ++iter)
	{
		if (pt == *iter)
		{
			return true;
		}
	}
	return false;
}

void Neuro_PtList_linked::PrintPt()
{
	int count = 0;
	for (auto iter = this->data.begin(); iter != this->data.end(); ++iter)
	{
		cout << "[" << count << "] " << iter->x << " " << iter->y << " " << iter->z << endl;
		++count;
	}
}

NeuroPoint & Neuro_PtList_linked::at(const int & n)
{
	auto iter = data.begin();
	for (int i = 0; i < n; ++i)
	{
		++iter;
	}
	return *iter;
}

NeuroPoint Neuro_PtList_linked::at_pt(const size_t & n) const
{
	auto iter = data.begin();
	for (int i = 0; i < n; ++i)
	{
		++iter;
	}
	return *iter;
}

NeuroPoint Neuro_PtList_linked::at_pt(const int & n) const
{
	auto iter = data.begin();
	for (int i = 0; i < n; ++i)
	{
		++iter;
	}
	return *iter;
}

NeuroPoint Neuro_PtList_linked::at_pt(const long long & n) const
{
	auto iter = data.begin();
	for (int i = 0; i < n; ++i)
	{
		++iter;
	}
	return *iter;
}

bool Neuro_PtList_linked::isEmpty()
{
	return data.empty();
}

void Neuro_PtList_linked::unique()
{
	data.unique();
}

list<NeuroPoint>::iterator Neuro_PtList_linked::begin()
{
	// TODO: 在此处插入 return 语句
	return this->data.begin();
}

list<NeuroPoint>::iterator Neuro_PtList_linked::end()
{
	return this->data.end();
}


