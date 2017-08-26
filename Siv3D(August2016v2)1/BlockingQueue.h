#pragma once
#include <queue>
#include <mutex>

template <typename T>
class blocking_queue {
public:
	blocking_queue() {}
	void enqueue(const T& item) {
		{
			std::lock_guard<std::mutex> lock(lk_);
			queue_.push(item);
		}
	}

	T dequeue() {
		std::lock_guard<std::mutex> lk(lk_);

		T result = queue_.front();
		queue_.pop();
		return result;
	}

	size_t size() const {
		std::lock_guard<std::mutex> lock(lk_);
		return queue_.size();
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lock(lk_);
		return queue_.empty();
	}

private:
	mutable std::mutex lk_;
	std::queue<T> queue_;
};
