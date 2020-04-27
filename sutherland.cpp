#include <iostream>
using namespace std;
typedef long long ll;

struct Path{
	ll start_hill;
	ll end_hill;
	ll t_tor;
	ll t_hare;
};
int main()
{
	int n,m;
	cin>>n>>m;
	Path path_array [m];
	for(int i=0;i<m;i++){
		cin>>path_array[i].start_hill>>path_array[i].end_hill>>path_array[i].t_tor>>path_array[i].t_hare;
    }
	return 0;
}
