/********************************************************************/
/* 版权声明：本文件提供的SharpNow SDK的版权属于天津锋时互动科技有限公司。 */
/* 本文件提供的SDK源码可能会发生更新与修改，您需承担使用本SDK的风险。     */
/* 个人或公司可以复制和使用此源码用于微动(ViD)应用程序开发。             */
/* (C) 2011-2015 Tianjin SharpNow Technology. All rights reserved.  */
/********************************************************************/

//! @file
//! 微动数学工具

#ifndef __SHARPNOW_TYPES_H__
#define __SHARPNOW_TYPES_H__

#include <string.h>
#include <math.h>

//! @namespace
namespace sharpnow
{

    //! @brief 类：二维向量
    //!
    //! 二维单精度实数向量，常用于表示平面坐标
    class Vector2 
    {
    public:
        float   x;  //!< x轴分量
        float   y;  //!< y轴分量

        Vector2() {}
        Vector2(float vx, float vy)                         { x = vx; y = vy;                   }
        Vector2(const Vector2& p)                           { x = p.x; y = p.y;                 }
        inline Vector2 operator -  () const                 { return Vector2(-x, -y);           }
        inline Vector2 operator +  (const Vector2& p) const { return Vector2(x + p.x, y + p.y); }
        inline Vector2 operator -  (const Vector2& p) const { return Vector2(x - p.x, y - p.y); }
        inline Vector2 operator *  (float d) const          { return Vector2(x*d, y*d);         }
        inline Vector2 operator /  (float d) const          { return (*this) * (1.0f / d);      }
        inline Vector2& operator =  (const Vector2& p)      { x = p.x; y = p.y; return *this;   }
        inline Vector2& operator += (const Vector2& p)      { x += p.x; y += p.y; return *this; }
        inline Vector2& operator -= (const Vector2& p)      { x -= p.x; y -= p.y; return *this; }
        inline Vector2& operator *= (float d)               { x *= d; y *= d; return *this;     }
        inline Vector2& operator /= (float d)               { return *this *= (1.0f / d);       }

        inline float    Length2() const { return x * x + y * y;     }
        inline float    Length() const  { return sqrtf(Length2());  }
        inline Vector2& Normalize()     { return *this /= Length(); }

    };

    //! @brief 类：三维向量
    //!
    //! 三维单精度实数向量，常用于表示空间坐标
    class Vector3
    {
    public:
        float   x;  //!< x轴分量
        float   y;  //!< y轴分量
        float   z;  //!< z轴分量

        Vector3() {}
        Vector3(float vx, float vy, float vz)               { x = vx; y = vy; z = vz;                       }
        Vector3(const Vector3& p)                           { x = p.x; y = p.y; z = p.z;                    }
        inline Vector3 operator -  () const                 { return Vector3(-x, -y, -z);                   }
        inline Vector3 operator +  (const Vector3& p) const { return Vector3(x + p.x, y + p.y, z + p.z);    }
        inline Vector3 operator -  (const Vector3& p) const { return Vector3(x - p.x, y - p.y, z - p.z);    }
        inline Vector3 operator *  (float d) const          { return Vector3(x*d, y*d, z*d);                }
        inline Vector3 operator /  (float d) const          { return (*this) * (1.0f / d);                  }
        inline Vector3& operator =  (const Vector3& p)      { x = p.x; y = p.y; z = p.z; return *this;      }
        inline Vector3& operator += (const Vector3& p)      { x += p.x; y += p.y; z += p.z; return *this;   }
        inline Vector3& operator -= (const Vector3& p)      { x -= p.x; y -= p.y; z -= p.z; return *this;   }
        inline Vector3& operator *= (float d)               { x *= d; y *= d; z *= d; return *this;         }
        inline Vector3& operator /= (float d)               { return *this *= (1.0f / d);                   }

        inline float    Length2() const { return x * x + y * y + z * z; }
        inline float    Length() const  { return sqrtf(Length2());      }
        inline Vector3& Normalize()     { return *this /= Length();     }
    };


    //! 三阶矩阵
    class Matrix3
    {
    public:
        float	D[3][3];

        Matrix3() {}
        Matrix3(const Matrix3& m) { Copy(m); }

        inline void Clear()                 { memset(D, 0, sizeof(float)*9);   }
        inline void Copy(const Matrix3 &m)  { memcpy(D, m.D, sizeof(float)*9); }

        inline Matrix3& operator = (const Matrix3& m)       { Copy(m); return *this; }
        inline float&   operator () (int y, int x)          { return D[y][x]; }
        inline float    operator () (int y, int x) const    { return D[y][x]; }

        inline Vector3  GetAxisX() const            { return Vector3(D[0][0], D[1][0], D[2][0]); }
        inline Vector3  GetAxisY() const            { return Vector3(D[0][1], D[1][1], D[2][1]); }
        inline Vector3  GetAxisZ() const            { return Vector3(D[0][2], D[1][2], D[2][2]); }
        inline Matrix3& SetAxisX(const Vector3& p)  { D[0][0] = p.x; D[1][0] = p.y; D[2][0] = p.z; return *this; }
        inline Matrix3& SetAxisY(const Vector3& p)  { D[0][1] = p.x; D[1][1] = p.y; D[2][1] = p.z; return *this; }
        inline Matrix3& SetAxisZ(const Vector3& p)  { D[0][2] = p.x; D[1][2] = p.y; D[2][2] = p.z; return *this; }
        inline Vector3  GetDiag() const             { return Vector3(D[0][0], D[1][1], D[2][2]); }
        inline Matrix3& SetDiag(const Vector3& p)   { D[0][0] = p.x; D[1][1] = p.y; D[2][2] = p.z; return *this; }
        inline Matrix3& Zero()                      { Clear(); return *this; } 
        inline Matrix3& Identity()                  { Clear(); D[0][0] = D[1][1] = D[2][2] = 1.0f; return *this; }

        Matrix3     operator +  (const Matrix3& m) const;
        Matrix3     operator -  (const Matrix3& m) const;
        Matrix3     operator -  () const;
        Matrix3     operator *  (const Matrix3& m) const;
        Matrix3     operator *  (float d) const;
        Vector3     operator *  (const Vector3& v) const;
        Matrix3     operator /  (float d) const;

        Matrix3&    operator += (const Matrix3& m);
        Matrix3&    operator -= (const Matrix3& m);
        Matrix3&    operator *= (const Matrix3& m);
        Matrix3&    operator *= (float d);
        Matrix3&    operator /= (float d);

        Matrix3&    SetRotX(float angle);     //!< 绕X轴旋转
        Matrix3&    SetRotY(float angle);     //!< 绕Y轴旋转
        Matrix3&    SetRotZ(float angle);     //!< 绕Z轴旋转
        Matrix3&    SetRot(const Vector3& axis, float angle);    //! 绕任意轴的旋转姿态

        //! 行列式值
        float Determinant() const;
        //! 转置矩阵
        Matrix3 Transpose() const;
        //! 矩阵求逆
        Matrix3 Inverse() const;

        //! 由旋转姿态计算卡尔登角
        void GetCardauAngle(Vector3& angle) const;
        //! 设置卡尔登角得到旋转矩阵
        void SetCardauAngle(const Vector3& angle);

    };

};

#endif
