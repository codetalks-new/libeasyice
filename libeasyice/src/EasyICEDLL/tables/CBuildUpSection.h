/*
MIT License

Copyright  (c) 2009-2019 easyice

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* Generated by Together */

#ifndef CBUILDUPSECTION_H
#define CBUILDUPSECTION_H
#include "section/CAnalyze.h"
#include "TsPacket.h"
#include "section/CParseSectionTogether.h"
namespace tables{
class CBuildUpSection {
public:

		~CBuildUpSection();

        CBuildUpSection();

		/**
         * 根据PID来组section
         * 如果此PID的section已经组完，则直接返回
         */
        void AddPacket(BYTE* pPacket, int nLength);

		 /**
         * 设置组好的section缓冲指针
         */
        void SetSectionBuffer(SECTION_BUFFER* p);

        /**
         * 设置解析完毕的缓冲指针
         */
        void SetTablesBuffer(TABLES* p);
private:

        /**
         * 表解析类对象
         */
        CAnalyze m_analyzer;

        /**
         * pid,sections
         * 每个pid组好的section
         */
        SECTION_BUFFER* m_pmapSectionData;

        /**
         * 存储的解析完毕的表的缓冲指针
         */
        TABLES* m_pTables;

        /**
         * section组合完毕，解析这个表的所有section
         * 不关心这是哪个表的数据，交由解析类处理。
         */
        void AnalyzeTable(int table_id, const TABLE_SECTIONS& table_sections);

private:

       inline void OnNotFindPid(BYTE* pPacket,int pid);

	   inline void OnFindedPid(BYTE* pPacket,int pid);

	   //如果section已经是完整的返回 -1
	   inline int AddDataToSections(BYTE* pPacket,TABLE_SECTIONS& sections);

	   //在vec后追加
	   inline void Vec_P_Copy(vector<BYTE>& vecData,BYTE* pData,int nLength);

	   inline void AddNewTable(BYTE* pPacket,PID_SECTION_BUILDING& pid_section_building);

	   //检测某个表是否组完,如果组完则设置标识.pPacket必须是payload为1 的ts包
	   inline void CheckTable(BYTE* pPacket,TABLE_ID_SECTION& table_id_section);

};

}
#endif //CBUILDUPSECTION_H
