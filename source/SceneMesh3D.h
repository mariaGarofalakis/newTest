#define EIGEN2_SUPPORT 1

#include <VVRScene/canvas.h>
#include <VVRScene/mesh.h>
#include <VVRScene/settings.h>
#include <VVRScene/utils.h>
#include <MathGeoLib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <set>
//include "symmetriceigensolver3x3.h"
#include <Eigen>
//dsdsa

#define FLAG_SHOW_AXES       1
#define FLAG_SHOW_WIRE       2
#define FLAG_SHOW_SOLID      4
#define FLAG_SHOW_NORMALS    8
#define FLAG_SHOW_PLANE     16
#define FLAG_SHOW_AABB      32
#define ERWTHMA_1           64
#define ERWTHMA_2           128
#define ERWTHMA_3           256
#define ERWTHMA_4           512
#define ERWTHMA_5           1024
#define PARAMORFWSH_EPIPEDOU 2048
#define PARAMORFWSH_NORMAL	4096
#define LIANSH 8192
#define TRIGWNA_SIGENIAS 16384
#define AKMES_MODELOU 32768
#define EPANATRIGWNOPOIHSH 65536

//vec apostash;

bool teleutos = false;
std::vector<vvr::Sphere3D> violations;
std::vector<Plane> epipedaa;
bool elenxos_akmes=false;
vec kedr_mazas;
Ray voh;
vvr::LineSeg3D la1;
vvr::LineSeg3D la2;
vvr::LineSeg3D la3;
Plane plane_axis(vec(0, 0, 0).Normalized(),0);
Plane katheto_epipedo;
vec m_norm;
vec kedro_mazas;
int trigwno=-1;
vec meso_normal1;
int Vathmos_sugenias_N=0;
int Vathmos_ipodiaireshs = 0;
void dual_graph(vvr::Mesh &mesh, Plane &plane, std::vector<vvr::LineSeg3D> &pleures_trigwou, std::vector<vvr::LineSeg3D> &dual_gr);
void meso_normal(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna);
void dimiourgia_upoperioxwn(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna, Plane &katheto_epipedo, std::vector<int> &panw_korifes, std::vector<int> &katw_korifes);
void diaxwrismos_epipedou_ep(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna, Plane &katheto_epipedo, std::vector<int> &panw_korifes, std::vector<int> &katw_korifes, int dir);
void diaxwrismos_epipedou_nor(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna, Plane &katheto_epipedo, std::vector<int> &panw_korifes, std::vector<int> &katw_korifes, int dir);
void anadromikh_upodiairesh(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna, std::vector<int> &teleutea_geitonika_trigwna, std::vector<vec> &arxikes_korifes, std::vector<float> &arxika_geitonika, std::vector<int> &nees_korifes, std::vector<int> &ekswteriko_monopati);
void liansh_perioxhs(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna, std::vector<vec> &arxikes_korifes, std::vector<float> &arxika_geitonika, std::vector<int> &nees_korifes);
void aktina_epiloghs(vvr::Mesh &mesh, Ray voh, std::vector<int> &geitonika_trigwna, std::vector<int> &teleutea_geitonika_trigwna);
void akmes_modelou(vvr::Mesh &mesh, Ray voh, std::vector<int> &geitonika_trigwna2, std::vector<int> &teleutea_geitonika_trigwna2, std::vector<int> &geitonika_trigwna, std::vector<int> &teleutea_geitonika_trigwna,std::vector<int> &ekswteriko_monopati);
void epanatrigwnopoihsh(vvr::Mesh &mesh, std::vector<int> &geitonika_trigwna);

class Mesh3DScene : public vvr::Scene
{	
public:
	Mesh3DScene();
	const char* getName() const { return "3D Scene"; }
	void keyEvent(unsigned char key, bool up, int modif) override;
	void mousePressed(int x, int y, int modif);
	void mouseReleased(int x, int y, int modif);
	void mouseMoved(int x, int y, int modif);
	void mouseWheel(int dir, int modif);
	void arrowEvent(vvr::ArrowDir dir, int modif) override;
	void printKeyboardShortcuts();
	
	

private:
	void draw() override;
	void reset() override;
	void resize() override;
	void Tasks();
	vec Task_3_Pick_Origin();
	vec* m_mouse_pos;

private:
	int m_style_flag;
	float m_plane_d;
	vvr::Canvas2D m_canvas;
	vvr::Colour m_obj_col;
	vvr::Mesh m_model_original, m_model;
	vvr::Box3D m_aabb;
	math::vec m_center_mass;
	math::vec m_pca_cen;
	math::vec m_pca_dir;
	math::Plane m_plane;
	std::vector<int> m_intersections;
	std::vector<int> enapomeinada;
	std::vector<int> seira;
	std::vector<int> oles;
	std::vector<vvr::Box3D> komatia;
	std::vector<vvr::Box3D>  teliko;
	std::vector<vvr::LineSeg3D> dual_gr;
	std::vector<vvr::LineSeg3D> pleures_trigwou;
	std::vector<vvr::LineSeg3D> akmes_vronxou;
	std::vector<int> geitonika_trigwna;
	std::vector<int> geitonika_trigwna2;
	std::vector<int> theseis_korifwn;
	std::vector<int> teleutea_geitonika_trigwna;
	std::vector<int> teleutea_geitonika_trigwna2;
	std::vector<int> ekswteriko_monopati;
	std::vector<int> panw_korifes;
	std::vector<int> katw_korifes;
	std::vector<vec> arxikes_korifes;
	std::vector<float> arxika_geitonika;
	std::vector<int> nees_korifes;
};
