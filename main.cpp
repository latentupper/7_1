#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

int main() {
    //1st task
    std::deque<int> d(10);
    std::iota(d.begin(), d.end(), 1);
    //check 1
    {
        std::cout << "1.  Generated deque:  ";
        for (auto i : d) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //2nd task
    std::uniform_int_distribution distr(1, 10);
    std::default_random_engine engine(std::chrono::steady_clock::now().time_since_epoch().count());
    for(unsigned i = 0; i < 5; i++) {
        d.push_front(distr(engine));
    }
    //check 2
    {
        std::cout << "2.  Generated deque:  ";
        for (auto i : d) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //3rd task
    std::vector<int> v;
    v.resize(d.size());
    copy(d.begin(), d.end(), v.begin());
    //check 3
    {
        std::cout << "3.  Copied vector:    ";
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //4th task
    sort(v.begin(), v.end(), std::greater<int>());
    //check 4
    {
        std::cout << "4.  Sorted vector:    ";
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //5th task
    std::shuffle(d.begin(), d.end(), engine);
    //check 5
    {
        std::cout << "5.  Shuffled deque:   ";
        for (auto i : d) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //6th task
    auto prod = std::inner_product(v.begin(), v.end(), d.begin(), 0);
    std::cout << "6.  Scalar product:   " << prod << " (using algorithm)"<< std::endl;
    //check 6
    {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += (v.at(i) * d.at(i));
        }
        std::cout << "6.  Scalar product:   " << sum << " (using loop to check algorithm)" << std::endl;
    }

    //7th task
    auto quant4 = std::count_if(v.begin(), v.end(), [](auto x){return x>4;});
    //check 7
    {
        std::cout << "7.  Nums > 4 in vec:  " << quant4 << std::endl;
    }

    //8th task
    auto summ = std::accumulate(v.begin(), v.end(), 0);
    //check 8
    {
        std::cout << "8.  Summ of vec el-s: " << summ << " (using algorithm)" << std::endl;
        int summ1 = 0;
        for (auto i : v) {
            summ1 += i;
        }
        std::cout << "8.  Summ of vec el-s: " << summ1 << " (using loop to check algorithm)" << std::endl;
    }

    //9th task
    auto pi = std::accumulate(d.begin(), d.end(), 1ull, [](auto x, auto y){return x*y;});
    //check 9
    {
        std::cout << "9.  Prod of deq el-s: " << pi << " (using algorithm)" << std::endl;
        unsigned long long pi1 = 1;
        for (auto i : d) {
            pi1 *= i;
        }
        std::cout << "9.  Prod of deq el-s: " << pi1 << " (using loop to check algorithm)" << std::endl;
    }

    //10th task
    auto start = std::remove_if(v.begin(), v.end(), [](auto x){return ((x>3) && (x%2 == 0));});
    v.erase(start, v.end());
    //check 10
    {
        std::cout << "10. Cleaned vector:   ";
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //11th task
    auto start1 = std::remove(d.begin(), d.end(), 4);
    d.erase(start1, d.end());
    //check 11
    {
        std::cout << "11. Cleaned deque:    ";
        for (auto i : d) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //12th task
    std::cout << "12. Vector output:    ";
    for(auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //13th task
    std::cout << "13. Deque output:     ";
    std::for_each(d.begin(), d.end(), [](auto& x){std::cout << x << " ";});
    std::cout << std::endl;

    //14th task
    auto dmm = std::minmax_element(d.begin(), d.end());
    auto vmm = std::minmax_element(v.begin(), v.end());
    std::cout << "14. Deque minimum:    " << *(dmm.first) << std::endl;
    std::cout << "14. Deque maximum:    " << *(dmm.second) << std::endl;
    std::cout << "14. Vector minimum:   " << *(vmm.first) << std::endl;
    std::cout << "14. Vector maximum:   " << *(vmm.second) << std::endl;

    return 0;
}
