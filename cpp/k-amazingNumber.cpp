#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        // vector<int> arr;
        int arr[100000];
        int inputCount = 0;
        // new code
        int distinctiveItem[100000];
        int distinctiveItemCount = 0;
        // new code
        while (inputCount < n)
        {
            int inp;
            scanf("%d", &inp);
            arr[inputCount] = inp;
            // new code
            bool matchFound = false;
            for (int q = 0; q < distinctiveItemCount + 1; q++)
            {
                if (distinctiveItem[q] == inp)
                {
                    matchFound = true;
                    break;
                }
            }
            if (!matchFound)
            {
                distinctiveItem[distinctiveItemCount] = inp;
                distinctiveItemCount++;
            }
            // new code

            inputCount++;
        }

        int k = 0;

        while (k < n) // k = 1
        {
            int ind = -1;
            bool existsInAllSubLayer1 = false;
            for (int j = 0; j <= distinctiveItemCount; j++)
            {
                int existInAllSub = false;
                for (int i = 0; (i + k) < inputCount; i++)
                {
                    bool existsInSubSegement = false;
                    for (int a = i; a <= (i + k); a++)
                    {
                        if (arr[a] == distinctiveItem[j])
                        {
                            existsInSubSegement = true;
                            break;
                        }
                    }
                    if (existsInSubSegement)
                    {
                        existInAllSub = true;
                    }
                    else
                    {
                        existInAllSub = false;
                        break;
                    }
                }
                if (existInAllSub)
                {
                    existsInAllSubLayer1 = true;
                    if (ind == -1)
                    {

                        ind = j;
                    }
                    else if (distinctiveItem[j] < distinctiveItem[ind])
                    {
                        ind = j;
                    }
                }
                else
                {
                    if (ind == -1)
                    {

                        existsInAllSubLayer1 = false;
                    }
                }
            }
            if (!existsInAllSubLayer1)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << distinctiveItem[ind] << endl;
            }
            k++;
        }
    }
}