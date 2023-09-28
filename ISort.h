#ifndef ISORT_H
#define ISORT_H

#include <iostream>
#include <vector>


class ISort
{
protected:
	int _comparisonCount{}, _swapCount{};

public:
	virtual void Sort(std::vector<int>& nums) = 0;
	virtual std::string GetSortName() = 0;
	int GetComparisons() const  { return _comparisonCount; };
	int GetSwaps() const { return _swapCount; };
	virtual ~ISort() = default;
};


class BubbleSort : public ISort
{
public:
	std::string GetSortName() { return "Пузырьковая сортировка: "; }
	void Sort(std::vector<int>& nums) override;
};


class SelectionSort : public ISort
{
public:
	std::string GetSortName() { return "Сортировка методом отбора: "; }
	void Sort(std::vector<int>& nums) override;
};


class InsertionSort : public ISort
{
public:
	std::string GetSortName() { return "Сортировка методом вставки: "; }
	void Sort(std::vector<int>& nums) override;
};


class ShellSort : public ISort
{
public:
	std::string GetSortName() { return "Сортировка методом Шелла: "; }
	void Sort(std::vector<int>& nums) override;
};


class QuickSort : public ISort
{
public:
	std::string GetSortName() { return "Быстрая сортировка: "; }
	void SortPartition(std::vector<int>& arr, int left, int right);
	void Sort(std::vector<int>& arr) override;
};



#endif