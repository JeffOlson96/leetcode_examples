/*
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, 
compute how much water it is able to trap after raining.



4|
 |
3|
 |
2|								*
 |				*	$	$	$	*	*
1|		*	$	*	*	$	*	*	*
 |________________________________

 	elevation map is represented by array
 	[0,1,0,2,1,0,1,3,2]
 	** are rocks
 	$$ is water
 	tabs for each idx

 	water stays where ever there is an index whose neighbors are bigger than it 
 	or if it has a neighbor that is the max and

 	output is how many spaces can be filled with water
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <vector>
#include <stack>

int TrappingRainWater(std::vector<int> map);
int Stack_TrappingRainWater(std::vector<int> &map);


int main()
{
	int elevationmap[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	std::vector<int> ele_vector;
	for (int i = 0; i < sizeof(elevationmap)/sizeof(elevationmap[0]); i++) {
		ele_vector.push_back(elevationmap[i]);
	}
	int num = TrappingRainWater(ele_vector);
	std::cout << "num: " << num << std::endl;

	int num2 = Stack_TrappingRainWater(ele_vector);
	std::cout << "num2: " << num2 << std::endl;
	return 0;

}



// brute force
// returns number of spaces that water can be trapped in
int TrappingRainWater(std::vector<int> map)
{
	int num = 0;
    for (int i = 1; i < map.size() - 1; i++) {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--) 
        { 
            max_left = std::max(max_left, map[j]);
        }
        for (int k = i; k < map.size(); k++) 
        { 
            max_right = std::max(max_right, map[k]);
        }
        num += std::min(max_left, max_right) - map[i];
    }
    return num;
}

// using stack
// O(n) instead
int Stack_TrappingRainWater(std::vector<int>&map)
{
	int num = 0, cur = 0;
	std::stack <int> water;
	while (cur < map.size())
	{
		while(!water.empty() && map[cur] > map[water.top()])
		{
			int top = water.top();
			water.pop();
			if (water.empty()){break;}

			int dist = cur - water.top()-1;
			int depth = std::min(map[cur], map[water.top()]) - map[top];
			num += dist * depth;
		}
		water.push(cur++);
	}
	return num;

}






