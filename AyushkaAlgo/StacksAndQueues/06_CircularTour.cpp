#include <queue>

void normalize(int &a,int n){
	a = a % n;
	cout << a << endl;
}



int tour(petrolPump p[],int n){

	for(int i = 0;i < n;i++){
		p[i].petrol -= p[i].distance;
	}


	int start = 0,end = 1,sum = 0;
	int size = 0, num = 0;
	int insandouts = 0;
	
	while(start !=0 or end!=0){
	    //cout << start << " " <<  end << " " <<  sum << " " <<  size << " " << insandouts << "\n";
		if(end == 0) sum = sum + p[n-1].petrol;
		else sum = sum + p[end-1].petrol;
		insandouts++;
		if(sum > 0){
			end++;
			end %= n;
			size++;
			
		}
		else if(sum <= 0){
			while(sum <= 0 and start != end){
				sum = sum - p[start].petrol;
				start++;
				start %= n;
				size--;
				insandouts++;
			}	

			if(start == end){
				end++;
				size++;
			}
		}
		num++;
		//if(num == 10) break;
		if(size == n or insandouts == 3*(n+1)) break;
	}
	if(size == n)
	return start;
	else return -1;
}

// C program to find circular tour for a truck
#include <stdio.h>
 
// A petrol pump has petrol and distance to next petrol pump
struct petrolPump
{
  int petrol;
  int distance;
};
 
// The function returns starting point if there is a possible solution,
// otherwise returns -1
int printTour(struct petrolPump arr[], int n)
{
    // Consider first petrol pump as a starting point
    int start = 0;
    int end =  1;
 
    int curr_petrol = arr[start].petrol - arr[start].distance;
 
    /* Run a loop while all petrol pumps are not visited.
      And we have reached first petrol pump again with 0 or more petrol */
    while (end != start || curr_petrol < 0)
    {
        // If curremt amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while (curr_petrol < 0 && start != end)
        {
            // Remove starting petrol pump. Change start
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1)%n;
 
            // If 0 is being considered as start again, then there is no
            // possible solution
            if (start == 0)
               return -1;
        }
 
        // Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;
 
        end = (end + 1)%n;
    }
 
    // Return starting point
    return start;
}
 
// Driver program to test above functions
int main()
{
    struct petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);
 
    (start == -1)? printf("No solution"): printf("Start = %d", start);
 
    return 0;
}