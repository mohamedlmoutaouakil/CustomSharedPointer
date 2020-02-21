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

	CustomSharedPointer(size_t size)
	{
		try                               // Add a try block
		{
			heap_ptr_ = new T[size];
			nbr_owners_ = new int[1];
			*nbr_owners_ = 1;
		}
		catch (...)
		{
			delete[] nbr_owners_;    // If there is an exception make sure the object is deleted.
			delete[] heap_ptr_;
			throw;             // Then re-throw the exception.
		}
	}

	CustomSharedPointer(T* ptr)
	{
		heap_ptr_ = ptr;
		try                               // Add a try block
		{
			nbr_owners_ = new int[1];
			*nbr_owners_ = 1;
		}
		catch (...)
		{
			delete[] nbr_owners_;    // If there is an exception make sure the object is deleted.
			throw;             // Then re-throw the exception.
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