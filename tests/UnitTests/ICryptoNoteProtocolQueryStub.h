// Copyright (c) 2012-2015, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>

#include "CryptoNoteProtocol/ICryptoNoteProtocolObserver.h"
#include "CryptoNoteProtocol/ICryptoNoteProtocolQuery.h"

class ICryptoNoteProtocolQueryStub: public CryptoNote::ICryptoNoteProtocolQuery {
public:
  ICryptoNoteProtocolQueryStub() : peers(0), observedHeight(0), synchronized(false) {}

  virtual bool addObserver(CryptoNote::ICryptoNoteProtocolObserver* observer);
  virtual bool removeObserver(CryptoNote::ICryptoNoteProtocolObserver* observer);
  virtual uint32_t getObservedHeight() const;
  virtual size_t getPeerCount() const;
  virtual bool isSynchronized() const;

  void setPeerCount(uint32_t count);
  void setObservedHeight(uint32_t height);

  void setSynchronizedStatus(bool status);

private:
  size_t peers;
  uint32_t observedHeight;

  bool synchronized;
};
