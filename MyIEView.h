//Download by http://www.NewXing.com
// MyIEView.h : CMyIEView ��Ľӿ�
//


#pragma once


class CMyIEView : public CHtmlView
{
protected: // �������л�����
	CMyIEView();
	DECLARE_DYNCREATE(CMyIEView)

// ����
public:
	CMyIEDoc* GetDocument() const;

// ����
public:

// ��д
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMyIEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	void fill();

public:
	afx_msg void OnFill();
	afx_msg void OnFileNew();
	virtual void OnDownloadComplete();
	virtual void OnNavigateComplete2(LPCTSTR strURL);
};

#ifndef _DEBUG  // MyIEView.cpp �ĵ��԰汾
inline CMyIEDoc* CMyIEView::GetDocument() const
   { return reinterpret_cast<CMyIEDoc*>(m_pDocument); }
#endif
