#pragma once

template<typename T>
class CustomSharedPointer
{
private:
    T* heap_ptr_;
    int* nbr_owners_;
public:
    CustomSharedPointer()
        :heap_ptr_{nullptr}, nbr_owners_{nullptr}{

    }

	~CustomSharedPointer()
	{
		if (nbr_owners_ != nullptr && heap_ptr_ == nullptr)
		{
			--(*nbr_owners_);
			if (*nbr_owners_ == 0)
			{
				delete[] heap_ptr_;
				delete[] nbr_owners_;
			}
		}
	}

    T* get()
    {
        return heap_ptr_;
    }

    int get_nbr_owners()
    {
        return *nbr_owners_;
    }
};