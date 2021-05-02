//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_MERGESORT_H
#define ALGCPP_MERGESORT_H

class MergeSort : public Sort {
private:
    int* merge_sort(int *up, int *down, unsigned int left, unsigned int right)
    {
        if (left == right)
        {
            down[left] = up[left];
            return down;
        }

        unsigned int middle = (left + right) / 2;

        // разделяй и сортируй
        int *l_buff = merge_sort(up, down, left, middle);
        int *r_buff = merge_sort(up, down, middle + 1, right);

        // слияние двух отсортированных половин
        int *target = l_buff == up ? down : up;

        unsigned int l_cur = left, r_cur = middle + 1;
        for (unsigned int i = left; i <= right; i++)
        {
            if (l_cur <= middle && r_cur <= right)
            {
                if (l_buff[l_cur] < r_buff[r_cur])
                {
                    target[i] = l_buff[l_cur];
                    l_cur++;
                }
                else
                {
                    target[i] = r_buff[r_cur];
                    r_cur++;
                }
            }
            else if (l_cur <= middle)
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        return target;
    }


protected:
    std::string name() override {
        return "MergeSort";
    }

    void sort(int *arr, int n) override {
        merge_sort(arr, new int[n], 0, n - 1);
    }
};

#endif //ALGCPP_MERGESORT_H
