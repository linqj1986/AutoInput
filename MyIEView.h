//Download by http://www.NewXing.com
// MyIEView.h : CMyIEView 类的接口
//


#pragma once


class CMyIEView : public CHtmlView
{
protected: // 仅从序列化创建
	CMyIEView();
	DECLARE_DYNCREATE(CMyIEView)

// 属性
public:
	CMyIEDoc* GetDocument() const;

// 操作
public:

// 重写
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMyIEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	void fill();

public:
	afx_msg void OnFill();
	afx_msg void OnFileNew();
	virtual void OnDownloadComplete();
	virtual void OnNavigateComplete2(LPCTSTR strURL);
};

#ifndef _DEBUG  // MyIEView.cpp 的调试版本
inline CMyIEDoc* CMyIEView::GetDocument() const
   { return reinterpret_cast<CMyIEDoc*>(m_pDocument); }
#endif

