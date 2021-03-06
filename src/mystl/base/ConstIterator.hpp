#pragma once

namespace mystl
{
namespace base
{
	/**
	 * Const iterator.
	 * 
	 * @author Jeongho Nam <http://samchon.org>
	 */
	template <class Iterator>
	class ConstIterator
	{
	private:
		/**
		 * @hidden
		 */
		Iterator base_;

	public:
		/* ----------------------------------------------------------
			CONSTRUCTORS
		---------------------------------------------------------- */
		/**
		 * Initializer Constructor.
		 */
		ConstIterator(const Iterator &base)
		{
			this->base_ = base;
		};

	public:
		/* ----------------------------------------------------------
			ACCESSORS
		---------------------------------------------------------- */
		auto operator*() const -> const typename Iterator::value_type&
		{
			return this->base_.operator*();
		};

		auto operator->() const -> const typename Iterator::value_type*
		{
			return this->base_.operator->();
		};

		/**
		 * @hidden
		 */
		auto _Base() const -> const Iterator&
		{
			return this->base_;
		};

	public:
		/* ----------------------------------------------------------
			MOVERS
		---------------------------------------------------------- */
		auto operator--() -> ConstIterator<Iterator>&
		{
			--this->base_;
			return *this;
		};
		auto operator--(int) -> ConstIterator<Iterator>
		{
			ConstIterator<Iterator> it = *this;
			--(*this);

			return it;
		};
		auto operator-(size_t n) -> ConstIterator<Iterator>
		{
			ConstIterator<Iterator> it = *this;
			while (n-- != 0)
				--it;

			return it;
		};

		auto operator++() -> ConstIterator<Iterator>&
		{
			++this->base_;
			return *this;
		};
		auto operator++(int) -> ConstIterator<Iterator>
		{
			ConstIterator<Iterator> it = *this;
			++(*this);

			return it;
		};
		auto operator+(size_t n) -> ConstIterator<Iterator>
		{
			ConstIterator<Iterator> it = *this;
			while (n-- != 0)
				++it;

			return it;
		};

	public:
		/* ----------------------------------------------------------
			COMPARES
		---------------------------------------------------------- */
		auto operator==(const Iterator &obj) const -> bool
		{
			return this->base_ == obj;
		};
		auto operator==(const ConstIterator<Iterator> &obj) const -> bool
		{
			return this->operator==(obj.base_);
		};

		auto operator!=(const Iterator &obj) const -> bool
		{
			return !this->operator==(obj);
		};
		auto operator!=(const ConstIterator<Iterator> &obj) const -> bool
		{
			return !this->operator==(obj);
		};
	};
};
};