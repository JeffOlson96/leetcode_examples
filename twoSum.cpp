#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

std::vector<int> twoSum(std::vector<int> nums, int target);

int main()
{
	int myints[] = {6,7,11,2,8,20,14,28,18,22,3};
	std::vector<int> v;
	for (int i = 0; i < sizeof(myints)/sizeof(myints[0]); i++) {
		v.push_back(myints[i]);
	}
	std::vector<int> n;
	int tar = 50;
	n = twoSum(v, tar);
	//std::cout << n.size() << std::endl;
	std::cout << "n0: " << n[0] << std::endl;
	std::cout << "n1: " << n[1] << std::endl;
}

std::vector<int> twoSum(std::vector<int> nums, int target) 
{
	std::vector <int> _sums;
	//std::cout << "size: " << nums.size() << std::endl;
    for (int i = 0; i < nums.size(); i++) 
    {
        for (int j = i+1; j < nums.size(); j++)
        {
        	//std::cout << "i: " << i << "j: " << j << std::endl;
        	if (nums[j] + nums[i] == target) 
        	{
        		
	            _sums.push_back(i);
	            _sums.push_back(j);
    		}
        }
    }
    return _sums;
}

