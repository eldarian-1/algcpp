//
// Created by eldarian on 02.05.2021.
//

#ifndef ALGCPP_MERGESORT_H
#define ALGCPP_MERGESORT_H

template<class T>
class MergeSort : public Sort<T> {
private:
    T* merge_sort(T *up, T *down, unsigned int left, unsigned int right)
    {
        if (left == right)
        {
            down[left] = up[left];
            return down;
        }

        unsigned int middle = (left + right) / 2;

        // разделяй и сортируй
        T *l_buff = merge_sort(up, down, left, middle);
        T *r_buff = merge_sort(up, down, middle + 1, right);

        // слияние двух отсортированных половин
        T *target = l_buff == up ? down : up;

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
    const char *name() override {
        return "MergeSort";
    }

    void sort(T *arr, int n) override {
        T *temp = new T[n];
        merge_sort(arr, temp, 0, n - 1);
        delete[] temp;
    }
};

#endif //ALGCPP_MERGESORT_H
