#pragma once
#include "Common/Defines.h"
#include "Common/BitVector.h"
#include "Common/ArrayView.h"

namespace bOPRF
{
	class CuckooHasher
	{
	public:
		CuckooHasher();
		~CuckooHasher();

		struct Bucket
		{
			Bucket()
				: mIdx(-1),
				  mHashIdx(0)
			{
			}

			Bucket(u64 i, u64 v)
				: mIdx(i), mHashIdx(v) {}

			u64 mIdx;
			u64 mHashIdx;

			bool isEmpty() const
			{
				return mIdx == u64(-1);
			}
		};

		typedef std::vector<Bucket> Bin;

		u64 mBinCount, mCuckooSize, mSimpleSize, mMaxStashSize, mSendersMaxBinSize, mTotalTries;

		std::vector<Bin> mBins;
		std::vector<u64> lastEvicted;
		std::vector<Bucket> mStash;

		void print() const;

		void init(u64 cuckooSize, u64 simpleSize);
		void insertItem(u64 IdxItem, std::array<std::vector<block>, 4> &hashs, u64 hashIdx = 0, u64 numTries = 0);
		void insertItems(std::array<std::vector<block>, 4> &hashs);
	};

}
