/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
#pragma once

#include "sam/base/stdcontainers.h"
#include "sam/vis/connect.h"

class ConnectPartitionner {
  private:
    vsy::map<Vint, Vint> m_elementIndexPartitionIndexTable; /* left ElementIndex, right Partition Index*/

    vis_Connect* m_inputConnect = nullptr;
    Vint m_elementCount = 0;
    Vint m_nodeCount = 0;
    Vint m_totalElementNodes = 0;

  public:
    VKI_EXTERN
    ConnectPartitionner(vis_Connect* connect);

    VKI_EXTERN void
    buildElementPartitions(const int partitionCount, Vint partitionSeed, bool propIdAsPartitionIdFlag);

    VKI_EXTERN void
    setElementPartitions(const vsy::map<Vint, Vint>& elementIndexPartitionIndexTable);

    VKI_EXTERN Vint
    getPartitionIndexFromElement(Vint elementIndex) const;

    VKI_EXTERN vsy::vector<Vint>
    getElementIndicesFromPartition(Vint partitionIndex) const;
};
