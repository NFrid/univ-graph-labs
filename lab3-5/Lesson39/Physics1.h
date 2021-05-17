#include <math.h>

class Vector3D {
  public:
  float x;
  float y;
  float z;

  Vector3D() {
    x = 0;
    y = 0;
    z = 0;
  }

  Vector3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  Vector3D& operator=(Vector3D v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
  }

  Vector3D operator+(Vector3D v) {
    return Vector3D(x + v.x, y + v.y, z + v.z);
  }

  Vector3D operator-(Vector3D v) {
    return Vector3D(x - v.x, y - v.y, z - v.z);
  }

  Vector3D operator*(float value) {
    return Vector3D(x * value, y * value, z * value);
  }

  Vector3D operator/(float value) {
    return Vector3D(x / value, y / value, z / value);
  }

  Vector3D& operator+=(Vector3D v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vector3D& operator-=(Vector3D v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  Vector3D& operator*=(float value) {
    x *= value;
    y *= value;
    z *= value;
    return *this;
  }

  Vector3D& operator/=(float value) {
    x /= value;
    y /= value;
    z /= value;
    return *this;
  }

  Vector3D operator-() {
    return Vector3D(-x, -y, -z);
  }

  float length() {
    return sqrtf(x * x + y * y + z * z);
  };

  void unitize() {
    float length = this->length();

    if (length == 0)
      return;

    x /= length;
    y /= length;
    z /= length;
  }

  Vector3D unit() {
    float length = this->length();

    if (length == 0)
      return *this;

    return Vector3D(x / length, y / length, z / length);
  }
};

class Mass {
  public:
  float    m;
  Vector3D pos;
  Vector3D vel;
  Vector3D force;

  Mass(float m) {
    this->m = m;
  }

  void applyForce(Vector3D force) {
    this->force += force;
  }

  void init() {
    force.x = 0;
    force.y = 0;
    force.z = 0;
  }

  void simulate(float dt) {
    vel += (force / m) * dt;

    pos += vel * dt;
  }
};

class Simulation {
  public:
  int    numOfMasses;
  Mass** masses;

  Simulation(int numOfMasses, float m) {
    this->numOfMasses = numOfMasses;

    masses = new Mass*[numOfMasses];

    for (int a = 0; a < numOfMasses; ++a)
      masses[a] = new Mass(m);
  }

  virtual void release() {
    for (int a = 0; a < numOfMasses; ++a) {
      delete (masses[a]);
      masses[a] = NULL;
    }

    delete (masses);
    masses = NULL;
  }

  Mass* getMass(int index) {
    if (index < 0 || index >= numOfMasses)
      return NULL;

    return masses[index];
  }

  virtual void init() {
    for (int a = 0; a < numOfMasses; ++a)
      masses[a]->init();
  }

  virtual void solve() {
  }

  virtual void simulate(float dt) {
    for (int a = 0; a < numOfMasses; ++a)
      masses[a]->simulate(dt);
  }

  virtual void operate(float dt) {
    init();
    solve();
    simulate(dt);
  }
};

class ConstantVelocity : public Simulation {
  public:
  ConstantVelocity()
      : Simulation(1, 1.0f) {
    masses[0]->pos = Vector3D(0.0f, 0.0f, 0.0f);
    masses[0]->vel = Vector3D(1.0f, 0.0f, 0.0f);
  }
};

class MotionUnderGravitation : public Simulation {
  public:
  Vector3D gravitation;

  MotionUnderGravitation(Vector3D gravitation)
      : Simulation(1, 1.0f) {
    this->gravitation = gravitation;
    masses[0]->pos    = Vector3D(-10.0f, 0.0f, 0.0f);
    masses[0]->vel    = Vector3D(10.0f, 15.0f, 0.0f);
  }

  virtual void solve() {
    for (int a = 0; a < numOfMasses; ++a)
      masses[a]->applyForce(gravitation * masses[a]->m);
  }
};

class MassConnectedWithSpring : public Simulation {
  public:
  float    springConstant;
  Vector3D connectionPos;

  MassConnectedWithSpring(float springConstant)
      : Simulation(1, 1.0f) {
    this->springConstant = springConstant;

    connectionPos = Vector3D(0.0f, -5.0f, 0.0f);

    masses[0]->pos = connectionPos + Vector3D(10.0f, 0.0f, 0.0f);
    masses[0]->vel = Vector3D(0.0f, 0.0f, 0.0f);
  }

  virtual void solve() {
    for (int a = 0; a < numOfMasses; ++a) {
      Vector3D springVector = masses[a]->pos - connectionPos;
      masses[a]->applyForce(-springVector * springConstant);
    }
  }
};
