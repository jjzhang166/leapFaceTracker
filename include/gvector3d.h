#ifndef GVECTOR3D_H
#define GVECTOR3D_H

#include <math.h>
#include "gmath.h"
#include "gpoint3d.h"

class GMatrix3d;

class GVector3d : public GPoint3d
{
protected:
    GVector3d operator * (const GMatrix3d &m) const;
	void operator *= (const GMatrix3d &m);    
public:
    GVector3d() : GPoint3d() {}
	GVector3d(double x, double y, double z) : GPoint3d(x, y, z) {}
	GVector3d(const double *v) : GPoint3d(v) {}
	GVector3d(const GPoint3d &v) : GPoint3d(v) {}
	//----ʸ������--------------------------------------------------------------
	
	// �����ӷ� 
	GVector3d operator + (const GVector3d &v) const;
	void operator += (const GVector3d &v);

    // �������� 
	GVector3d operator - (const GVector3d &v) const;
	void operator -= (const GVector3d &v);
	GVector3d operator - () const;

    // �������� 
	GVector3d operator * (double d) const;
	void operator *= (double d);

    // �������� 
	GVector3d operator / (double d) const;
	void operator /= (double d);

    // ������� 
	GVector3d crossMult(const GVector3d &v) const;
	
	// ������� 
	double dotMult(const GVector3d &v) const;

    // �������� 
	double getLength() const;
	// ������XOYƽ���ϳ��� 
	double getLengthXY() const;
	// ������YOZƽ���ϳ��� 
	double getLengthYZ() const;
	// ������ZOXƽ���ϳ��� 
	double getLengthZX() const;
	// �Ƿ�Ϊ0�������� 
	bool isZero() const;

    // �õ���һ������ 
	GVector3d getNormal() const;
	// ��������һ�� 
	void normalize();
	
	// �õ����任����m�任������� 
	GVector3d transformTo(const GMatrix3d &m) const;
};

#endif
