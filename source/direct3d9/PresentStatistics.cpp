/*
* Copyright (c) 2007-2012 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#include "stdafx.h"

#include "PresentStatistics.h"

using namespace System;

namespace SlimDX
{
namespace Direct3D9
{ 	
	PresentStatistics::PresentStatistics( const D3DPRESENTSTATS& native )
	{
		m_PresentCount = native.PresentCount;
		m_PresentRefreshCount = native.PresentRefreshCount;
		m_SyncRefreshCount = native.SyncRefreshCount;
		m_SyncQPCTime = native.SyncQPCTime.QuadPart;
		m_SyncGPUTime = native.SyncGPUTime.QuadPart;
	}

	int PresentStatistics::PresentCount::get()
	{
		return m_PresentCount;
	}

	int PresentStatistics::PresentRefreshCount::get()
	{
		return m_PresentRefreshCount;
	}

	int PresentStatistics::SyncRefreshCount::get()
	{
		return m_SyncRefreshCount;
	}

	Int64 PresentStatistics::SyncQPCTime::get()
	{
		return m_SyncQPCTime;
	}

	Int64 PresentStatistics::SyncGPUTime::get()
	{
		return m_SyncGPUTime;
	}

	bool PresentStatistics::operator == ( PresentStatistics left, PresentStatistics right )
	{
		return PresentStatistics::Equals( left, right );
	}

	bool PresentStatistics::operator != ( PresentStatistics left, PresentStatistics right )
	{
		return !PresentStatistics::Equals( left, right );
	}

	int PresentStatistics::GetHashCode()
	{
		return m_PresentCount.GetHashCode() + m_PresentRefreshCount.GetHashCode() + m_SyncRefreshCount.GetHashCode()
			 + m_SyncQPCTime.GetHashCode() + m_SyncGPUTime.GetHashCode();
	}

	bool PresentStatistics::Equals( Object^ value )
	{
		if( value == nullptr )
			return false;

		if( value->GetType() != GetType() )
			return false;

		return Equals( safe_cast<PresentStatistics>( value ) );
	}

	bool PresentStatistics::Equals( PresentStatistics value )
	{
		return ( m_PresentCount == value.m_PresentCount && m_PresentRefreshCount == value.m_PresentRefreshCount && m_SyncRefreshCount == value.m_SyncRefreshCount
			 && m_SyncQPCTime == value.m_SyncQPCTime && m_SyncGPUTime == value.m_SyncGPUTime );
	}

	bool PresentStatistics::Equals( PresentStatistics% value1, PresentStatistics% value2 )
	{
		return ( value1.m_PresentCount == value2.m_PresentCount && value1.m_PresentRefreshCount == value2.m_PresentRefreshCount && value1.m_SyncRefreshCount == value2.m_SyncRefreshCount
			 && value1.m_SyncQPCTime == value2.m_SyncQPCTime && value1.m_SyncGPUTime == value2.m_SyncGPUTime );
	}
}
}
