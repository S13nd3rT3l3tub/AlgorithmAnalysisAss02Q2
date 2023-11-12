#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// Based on https://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/

// Psuedocode
/*
==============================================================
	1. Sort all points according to X axis
	2. Draw a vertical line down the midpoint, group the points in left and right
	3. Recursively find the smallest distance in the two containers
	4. Take the smallest between the two distance, d
	5. Create a container strip to store all the points which are at most d distance away from the midpoint
	6. Find smallest distance in strip container, d'
	7. Return the smallest between d and d'
==============================================================
*/

// Point in 2D plane
struct Point
{
	int x, y;
};

// Function to sort array according to X axis
int compareX(const void* a, const void* b)
{
	Point* p1 = (Point*)a;
	Point* p2 = (Point*)b;
	return p1->x - p2->x;
}

// Function to sort vector according to Y axis
bool compareY(Point a, Point b)
{
	return a.y < b.y;
}

// Function to calculate distance between two points
float dist(Point p1, Point p2)
{
	return (float)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to return the smallest distance between two points in P[] of size n
float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

// Function to find the minimum of two float values
float min(float x, float y)
{
	return (x < y) ? x : y;
}

// Function to find distance between the cloest points of strip of a given size
// strip vector is sorted according to Y axis
// O(n) as the inner loop runs at most 6 times
float stripClosest(std::vector<Point> strip, int size, float d)
{
	float min = d;
	std::sort(strip.begin(), strip.end(), compareY);
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++)
			if (dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);
	return min;
}

// Recursive function to find the smallest distance.
// O(nlgn)
float closestUtil(Point p[], int n)
{
	// Use brute force function if the number of points is <= 3
	if (n <= 3)
		return bruteForce(p, n);

	// Find the mid point
	int mid = n / 2;
	Point midPoint = p[mid];

	// Calculate closest distance between left and right
	float dl = closestUtil(p, mid);							// Depth of recursion: lgn
	float dr = closestUtil(p + mid, n - mid);
	float d = min(dl, dr);

	// Find all the points closer than d from the midpoint 
	std::vector<Point> strip;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(p[i].x - midPoint.x) < d)
		{
			strip.push_back(p[i]);
			j++;
		}
	}

	// Find the smallest distance d and the closest points in strip
	return min(d, stripClosest(strip, j, d)); // O(n)
}


float closest(Point p[], int n)
{
	qsort(p, n, sizeof(Point), compareX);
	return closestUtil(p, n);
}

int main() {
	Point p[] = { {2,3}, {12,30}, {40,50}, {5,1}, {12,10}, {3,4} };
	int n = sizeof(p) / sizeof(p[0]);
	std::cout << "The smallest distance is " << closest(p, n) << std::endl;
	return 0;
}