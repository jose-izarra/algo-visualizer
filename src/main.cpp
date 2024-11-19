#include "visualizer.h"
#include "algorithm.h"
#include <vector>
#include <thread>


using namespace visualizer;

int main() {

    // generate a random array with 100 random integers
    std::vector<int> arr;

    std::vector<std::vector<int>> sortingSteps;
    
    algorithm::randomNumberGen(arr, 300, 0, 100);

    SortVisualizer visualizer(1000, 1000, arr.size(), 300, "Merge Sort", "O(n log n)");

    algorithm::iterMergeSort(arr, [&sortingSteps](const std::vector<int>& step){
        sortingSteps.push_back(step);
    });

    

    // std::sort(arr.begin(), arr.end(), [&sortingSteps, &arr](int a, int b) {
    //     sortingSteps.push_back(arr);
    //     return a < b;
    // });

    for (const auto& step : sortingSteps) {
        visualizer.addState(step);
    }

    visualizer.visualize();

    return 0;
}