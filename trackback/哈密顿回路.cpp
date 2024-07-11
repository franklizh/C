// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 全局变量
// int n; // 顶点数
// vector<vector<int>> g; // 图的邻接矩阵
// vector<int> x; // 顶点排列,x[i]表示在第i次访问的结点号。

// void output(const vector<int>& x)
// {
//     for(int i=1;i<=n;i++)
//     {
//         cout<<x[i]<<" ";
//     }
//     cout<<x[1]<<endl;
// }

// void swap(int &a,int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }

// void hamilton(int t)
// {
//     //遍历到最后则输出
//     if(t>n&&g[x[t]][x[1]]==1)//满足最后一个点要与顶点相连
//     {
//         output(x);
//     }
//     else{
//         for(int i=t;i<=n;i++)
//         {
//             swap(x[t],x[i]);
//             //如果这个节点和上一个节点没有相连，则不再向下遍历
//             if(g[x[t]][x[t-1]]==1)//剪枝函数
//             {
//                 hamilton(i+1);
//             }
//             swap(x[i],x[t]);
//         }
//     }
// }

// int main()
// {
//     cout<<"enter number of g";
//     cin>>n;

//     g.resize(n+1,vector<int>(n+1,0));//初始化二维，全为0
//     x.resize(n+1);

//     cout<<"enter the adjacency matrix:"<<endl;
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             cin >> g[i][j];
//         }
//     }

//     // 初始化顶点排列
//     for (int i = 1; i <= n; ++i) {
//         x[i] = i;
//     }

//      // 从顶点 1 开始寻找哈密顿回路
//     hamilton(2);

// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 全局变量
int n; // 顶点数
vector<vector<int>> g; // 图的邻接矩阵
vector<int> x; // 顶点排列

// 输出函数
void output(const vector<int>& x) {
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << x[0] << endl; // 输出回到起点的路径
}

// 交换函数
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 剪枝函数
void hamilton(int t) {
    if (t == n && g[x[t - 1]][x[0]] == 1) {
        output(x); // 找到一个哈密顿回路
    } else {
        for (int i = t; i < n; ++i) {
            swap(x[t], x[i]);
            if (g[x[t]][x[t - 1]] == 1) { // 检查是否有边连接
                hamilton(t + 1);
            }
            swap(x[t], x[i]);
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    // 初始化图的邻接矩阵和顶点排列
    g.resize(n, vector<int>(n, 0));
    x.resize(n);

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    // 初始化顶点排列
    for (int i = 0; i < n; ++i) {
        x[i] = i;
    }

    // 从顶点 0 开始寻找哈密顿回路
    hamilton(1);

    return 0;
}
