#pragma once

template<typename T>
class Unique_ptr {
public:
	Unique_ptr() : ptr_(nullptr) {}
	Unique_ptr(T* source) : ptr_(source) {}

	Unique_ptr(const Unique_ptr&) = delete; // ������ ������������ ����������� 
	Unique_ptr operator=(const Unique_ptr&) = delete; // ������ ��������� ������������

	T& operator*() { return *ptr_; } // ���������� ������� �������� "*" ��� ��������� �������
	T* operator->() { return ptr; }

	T* release() {
		T* old_ptr = ptr_;
		ptr_ = nullptr;

		return old_ptr;
	}

	~Unique_ptr() { delete ptr_; }
private:
	T* ptr_;
	int count;
};