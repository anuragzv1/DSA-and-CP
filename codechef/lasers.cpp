#include <iostream>
#include<cmath>

using namespace std;

class line
{
public:
    double x1;
    double x2;
    double y1;
    double y2;
    double a;
    double b;
    double c;
};

class laser
{
public:
    double x1;
    double x2;
    double y1;
    double y2;
    double a;
    double b;
    double c;
};

bool intersects(laser l1 , line l2){
    int determinant = l1.a*l2.b -l2.a*l1.b;
    if(determinant!=0){
        double x = (l2.b*l1.c - l1.b*l2.c)/determinant;
        double y = (l1.a*l2.c-l2.a*l1.c)/determinant;
        if((l2.x2==l1.x1 && l2.y2==l1.y1) || (l2.x1==l1.x2 && l2.y1==l1.y2))return false;
        double minmx = min(l2.x1,l2.x2);
        double maxx = max(l2.x1,l2.x2);
        double miny = min(l2.y1,l2.y2);
        double maxy = max(l2.y1,l2.y2);

        double minmx1 = min(l1.x1,l1.x2);
        double maxx1 = max(l1.x1,l1.x2);
        double miny1 = min(l1.y1,l1.y2);
        double maxy1 = max(l1.y1,l1.y2);
        if(minmx > x || x>maxx)return false;
        if(miny > y || y >maxy)return false;
        if(minmx1 > x || x>maxx1)return false;
        if(miny1 > y || y>maxy1)return false;
        //cout<<"intersection pt "<<x<<" "<<y<<"minm x = "<<minmx<<" max x="<<maxx<<"min y = "<<miny<<" max y ="<<maxy<<endl;
        return true;
        }
    else return false;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        double arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }  
        line lines[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            double x1 = i+1;
            double y1 = arr[i];
            double x2 = i + 2;
            double y2 = arr[i + 1];
            double a = y2 - y1;
            double b = x1 - x2;
            double c = x1 * y2 - y1 * x2;
            
            lines[i].x1=x1;
            lines[i].x2=x2;
            lines[i].y1=y1;
            lines[i].y2=y2;
            lines[i].a = a;
            lines[i].b = b;
            lines[i].c = c;
        }

        for (int i = 0; i < q; i++)
        {
            double x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1;
            y2 = y1;
            double a = y2 - y1;
            double b = x1 - x2;
            double c = x1 * y2 - y1 * x2;
            laser l;
            l.x1=x1;
            l.x2=x2;
            l.y1=y1;
            l.y2=y2;
            l.a = a;
            l.b = b;
            l.c = c;
            int s=0;
            for(int x=0;x<n-1;x++){
                if(intersects(l , lines[x])){
                    //cout<<"("<<l.x1<<","<<l.y1<<")"<<"("<<l.x2<<","<<l.y2<<") intersect wth ("<<lines[x].x1<<","<<lines[x].y1<<")("<<lines[x].x2<<","<<lines[x].y2<<")\n";
                    s++;
                }
            }
            cout<<s<<endl;
        }
    }
}




// 2
// 4 3
// 1 3 5 1
// 2 4 4
// 1 2 3
// 1 4 1
// 4 3
// 1 3 5 1
// 2 4 4
// 1 2 3
// 1 4 1