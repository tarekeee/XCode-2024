#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> i;
    for (int count = 0; count < n; ++count)
    {
        int l, k;
        std::cin >> l >> k;
        i.push_back(std::make_pair(l, k));
    }

    for (int j = 0; j < n; ++j)
    {
        std::deque<int> a;
        for (int num = 1; num <= i[j].first; ++num)
        {
            a.push_back(num);
        }
  

        int item = 0;
        while (!a.empty())
        {
            int rotation = i[j].second - 1;
            for (int p = 0; p < rotation; p++)
            {
                int val = a.front();
                a.pop_front();
                a.push_back(val);
            }


            item = a.front();
            a.pop_front();

        }

        std::cout << item << "\n";
    }

    return 0;
}
