#include "SceneMesh3D.h"
//sdsada
using namespace std;
using namespace vvr;


Mesh3DScene::Mesh3DScene()
{
	
	m_bg_col = vvr::Colour::grey;
	m_perspective_proj = true;
	m_hide_log = false;
	m_hide_sliders = true;
	m_fullscreen = true;


	//! Load settings.
	vvr::Shape::DEF_LINE_WIDTH = 4;
	vvr::Shape::DEF_POINT_SIZE = 10;
	m_perspective_proj = true;
	m_bg_col = Colour("768E77");
	m_obj_col = Colour("454545");
	const string objDir = getBasePath() + "resources/obj/";
	const string objFile = objDir + "Rck-Wtrfll_obj.obj";
	m_model_original = vvr::Mesh(objFile);
	reset();
}

void Mesh3DScene::printKeyboardShortcuts(){
	std::cout << "Keyboard shortcuts:"
		<< std::endl << "'?' => This shortcut list:"
		<< std::endl << "'d' => DUAL_GRAPH"
		<< std::endl << "'c' => CLEAR_DUAL_GRAPH"
		<< std::endl << "'2' => ERWTHMA_2"
		<< std::endl << "'t' => epilogh perioxh vash ths sigenias"
		<< std::endl << "'a' => epilogh perioxh kloistoy vronxou akmwn"
		<< std::endl << "'3' => ERWTHMA_3"
		<< std::endl << "'k' => ERWTHMA_4"
		<< std::endl << "'p' => ERWTHMA_5"
		<< std::endl << "'o' => PARAMORFWSH_EPIPEDOU"
		<< std::endl << "'l' => PARAMORFWSH_NORMAL"
		<< std::endl << "'z' => LIANSH"
		<< std::endl << "'e' => EPANATRIGWNOPOIHSH"
		<< std::endl << std::endl;

	
	
}

void Mesh3DScene::reset()
{
	Scene::reset();

	//! Define plane
	m_plane_d = 0;
	m_plane = Plane(vec(0, 1, 1).Normalized(), m_plane_d);

	//! Define what will be vissible by default
	m_style_flag = 0;
	
//	m_style_flag |= ERWTHMA_2;
//	m_style_flag |= TRIGWNA_SIGENIAS;
//	m_style_flag |= AKMES_MODELOU;
//	m_style_flag |= ERWTHMA_3;
//	m_style_flag |= ERWTHMA_4;
//	m_style_flag |= ERWTHMA_5;
//	m_style_flag |= PARAMORFWSH_EPIPEDOU;
//	m_style_flag |= PARAMORFWSH_NORMAL;

	m_style_flag |= FLAG_SHOW_SOLID;
	m_style_flag |= FLAG_SHOW_SOLID;
	m_style_flag |= FLAG_SHOW_WIRE;
	m_style_flag |= FLAG_SHOW_AXES;
	m_style_flag |= FLAG_SHOW_AABB;
	//m_style_flag |= FLAG_SHOW_PLANE;
}

void Mesh3DScene::resize()
{
	//! By Making `first_pass` static and initializing it to true,
	//! we make sure that the if block will be executed only once.

	static bool first_pass = true;

	if (first_pass)
	{
		m_model_original.setBigSize(getSceneWidth() / 2);
		m_model_original.update();
		m_model = m_model_original;
		Tasks();
		first_pass = false;
	}
}

void Mesh3DScene::Tasks()
{
	printKeyboardShortcuts();
	m_model_original = m_model;
	Ray voh = Scene::unproject(m_center_mass.x, m_center_mass.y);
	math::vec nw = plane_axis.normal;
	nw = math::float3x3::RotateY(DegToRad(90)).Transform(nw);
	plane_axis = Plane(nw.Normalized(),0);
}
void Mesh3DScene::mousePressed(int x, int y, int modif){
	
	Scene::mousePressed(x, y, modif);
	
	trigwno = -1;
	voh = Scene::unproject(x, y);
	arxikes_korifes.clear();
	geitonika_trigwna.clear();
	teleutea_geitonika_trigwna.clear();
	teleutea_geitonika_trigwna2.clear();
	ekswteriko_monopati.clear();
	violations.clear();
	epipedaa.clear();
	teleutos = false;
	if (m_style_flag & ERWTHMA_2){
		std::cout << "epilogh trigwnou " << std::endl;
		akmes_vronxou.clear();

		if ((m_style_flag & TRIGWNA_SIGENIAS)){
			std::cout << "trigwna sigenias " << std::endl;
			aktina_epiloghs(m_model, voh, geitonika_trigwna, teleutea_geitonika_trigwna);
		}
		if ((m_style_flag & AKMES_MODELOU)){
			std::cout << "akmes modelou " << std::endl;
			akmes_modelou(m_model, voh, geitonika_trigwna2, teleutea_geitonika_trigwna2, geitonika_trigwna, teleutea_geitonika_trigwna,ekswteriko_monopati);
			if (ctrlDown(modif))
			{
				geitonika_trigwna2.clear();

			}

		}
	}

	

	
	if (m_style_flag & ERWTHMA_3){
		std::cout << "anadromikh ipodieresh " << std::endl;
		anadromikh_upodiairesh(m_model, geitonika_trigwna, teleutea_geitonika_trigwna, arxikes_korifes, arxika_geitonika, nees_korifes,ekswteriko_monopati);
		for (int m = 0; m < ekswteriko_monopati.size(); m++){
			geitonika_trigwna.push_back(ekswteriko_monopati[m]);
		}

		ekswteriko_monopati.clear();
		geitonika_trigwna2.clear();
	}
	if (m_style_flag & ERWTHMA_4){
		if (!(m_style_flag & ERWTHMA_3)){
			for (int m = 0; m < ekswteriko_monopati.size(); m++){
				geitonika_trigwna.push_back(ekswteriko_monopati[m]);
			}
		}
		meso_normal(m_model, geitonika_trigwna);
	}
	if (m_style_flag & ERWTHMA_5){
		std::cout << "dhmiourgia upoperioxwn " << std::endl;
		if (!(m_style_flag & ERWTHMA_3)){
			for (int m = 0; m < ekswteriko_monopati.size(); m++){
				geitonika_trigwna.push_back(ekswteriko_monopati[m]);
			}
		}
		dimiourgia_upoperioxwn(m_model, geitonika_trigwna, katheto_epipedo, panw_korifes, katw_korifes);
	}

	
}
void Mesh3DScene::mouseReleased(int x, int y, int modif){




}
void Mesh3DScene::mouseMoved(int x, int y,  int modif){
		
	Scene::mouseMoved(x, y, modif);

}

void Mesh3DScene::mouseWheel(int dir, int modif){
	// epilegoume thn apostash pou 8a exoun apo to epipedo oi dio epilegmenes perioxes
	
	if (m_style_flag & ERWTHMA_5){	
		if (m_style_flag &  PARAMORFWSH_EPIPEDOU){
			echo("paramorfwnh sxhmatos meso tou epipedou");
			diaxwrismos_epipedou_ep(m_model, geitonika_trigwna, katheto_epipedo, panw_korifes, katw_korifes, dir);
			if (m_style_flag & EPANATRIGWNOPOIHSH){
			//	epanatrigwnopoihsh(m_model, geitonika_trigwna);
			}
		}
		if (m_style_flag &  PARAMORFWSH_NORMAL){
			echo("paramorfwnh sxhmatos meso tou normal");
			diaxwrismos_epipedou_nor(m_model, geitonika_trigwna, katheto_epipedo, panw_korifes, katw_korifes, dir);
			if (m_style_flag & EPANATRIGWNOPOIHSH){
		//		epanatrigwnopoihsh(m_model, geitonika_trigwna);
			}
		}
		
	}
	else{
		Scene::mouseWheel(dir, modif);
	}

}

void Mesh3DScene::arrowEvent(ArrowDir dir, int modif)
{
	if (dir == UP) { 
		Vathmos_sugenias_N += 1;
		std::cout<<"o vathmos sugenias trigwnwn isoutai me: " << Vathmos_sugenias_N << std::endl;
	}
	if (dir == DOWN&&Vathmos_sugenias_N>0){
		Vathmos_sugenias_N -= 1;
		std::cout << "o vathmos sugenias trigwnw isoutai me: " << Vathmos_sugenias_N << std::endl;
	}
	if (dir == LEFT){
		Vathmos_ipodiaireshs += 1;
		std::cout << "o vathmos ipodiereshs twn trigwnwn isoutai me: " << Vathmos_ipodiaireshs << std::endl;
		
	}
	if (dir == RIGHT&&Vathmos_ipodiaireshs>0){
		Vathmos_ipodiaireshs -= 1;
		std::cout << "o vathmos ipodiereshs twn trigwnwn isoutai me: " << Vathmos_ipodiaireshs << std::endl;
		
	}

}

void Mesh3DScene::keyEvent(unsigned char key, bool up, int modif)
{
	Scene::keyEvent(key, up, modif);
	key = tolower(key);

	switch (key)
	{
	
	case 'd': dual_graph(m_model, m_plane, pleures_trigwou, dual_gr); break;
	case '2': m_style_flag ^= ERWTHMA_2; break;
	case 't': m_style_flag ^= TRIGWNA_SIGENIAS; break;
	case 'a': m_style_flag ^= AKMES_MODELOU; break;
	case '3': m_style_flag ^= ERWTHMA_3; break;
	case 'k': m_style_flag ^= ERWTHMA_4; break;
	case 'p': m_style_flag ^= ERWTHMA_5; break;
	case 'o': m_style_flag ^= PARAMORFWSH_EPIPEDOU; break;
	case 'l': m_style_flag ^= PARAMORFWSH_NORMAL; break;
	case 'z': liansh_perioxhs(m_model, geitonika_trigwna, arxikes_korifes,arxika_geitonika, nees_korifes); break;
//	case 'e': m_style_flag ^= EPANATRIGWNOPOIHSH; break;
	case 'e':epanatrigwnopoihsh(m_model, geitonika_trigwna);
	case 's': m_style_flag ^= FLAG_SHOW_SOLID; break;
	case 'w': m_style_flag ^= FLAG_SHOW_WIRE; break;
	case 'n': m_style_flag ^= FLAG_SHOW_NORMALS; break;
	case 'b': m_style_flag ^= FLAG_SHOW_AABB; break;

	}
	if (key == '?')
	{
		printKeyboardShortcuts();
	}
	else if (key == 'c'){
		//katharismos dihkou grafou
		dual_gr.clear();
	}
}

void Mesh3DScene::draw()
{
	//! Draw plane
	if (m_style_flag & FLAG_SHOW_PLANE) {
		vvr::Colour colPlane(0x41, 0x14, 0xB3);
		float u = 20, v = 20;
		math::vec p0(m_plane.Point(-u, -v, math::vec(0, 0, 0)));
		math::vec p1(m_plane.Point(-u, v, math::vec(0, 0, 0)));
		math::vec p2(m_plane.Point(u, -v, math::vec(0, 0, 0)));
		math::vec p3(m_plane.Point(u, v, math::vec(0, 0, 0)));
		math2vvr(math::Triangle(p0, p1, p2), colPlane).draw();
		math2vvr(math::Triangle(p2, p1, p3), colPlane).draw();
	}

	if (m_style_flag & FLAG_SHOW_SOLID) m_model.draw(m_obj_col, SOLID);
	if (m_style_flag & FLAG_SHOW_WIRE) m_model.draw(Colour::black, WIRE);
	if (m_style_flag & FLAG_SHOW_NORMALS) m_model.draw(Colour::red, NORMALS);
	if (m_style_flag & FLAG_SHOW_AXES) m_model.draw(Colour::black, AXES);

	
	vector<vvr::Triangle> &triangles = m_model.getTriangles();

	
	LineSeg3D lo(voh.pos.x, voh.pos.y, voh.pos.z, voh.pos.x + 50000 * voh.dir.x, voh.pos.y + 50000 * voh.dir.y, voh.pos.z + 50000 * voh.dir.z, vvr::Colour::red);
	lo.draw();

	if ((m_style_flag & AKMES_MODELOU)){
		if (!(geitonika_trigwna2.empty())){
			for (int metr = 0; metr < ekswteriko_monopati.size(); metr++){
				vvr::Triangle &tr2 = triangles[ekswteriko_monopati[metr]];
				Triangle3D trg3d(
					tr2.v1().x, tr2.v1().y, tr2.v1().z,
					tr2.v2().x, tr2.v2().y, tr2.v2().z,
					tr2.v3().x, tr2.v3().y, tr2.v3().z,
					Colour::darkOrange);
				trg3d.draw();


			}
			if (!(m_style_flag & ERWTHMA_3)){
				for (int metr2 = 0; metr2 < geitonika_trigwna2.size(); metr2++){
					vvr::Triangle &tr2 = triangles[geitonika_trigwna2[metr2]];
					Triangle3D trg3d(
						tr2.v1().x, tr2.v1().y, tr2.v1().z,
						tr2.v2().x, tr2.v2().y, tr2.v2().z,
						tr2.v3().x, tr2.v3().y, tr2.v3().z,
						Colour::green);
					trg3d.draw();


				}
			}

		}
		if (!(teleutea_geitonika_trigwna2.empty())){
			if (!(m_style_flag & ERWTHMA_3)){
				for (int metr2 = 0; metr2 < teleutea_geitonika_trigwna2.size(); metr2++){

					vvr::Triangle &tr2 = triangles[teleutea_geitonika_trigwna2[metr2]];
					Triangle3D trg3d(
						tr2.v1().x, tr2.v1().y, tr2.v1().z,
						tr2.v2().x, tr2.v2().y, tr2.v2().z,
						tr2.v3().x, tr2.v3().y, tr2.v3().z,
						Colour::red);
					trg3d.draw();


				}
			}

		}
	}
	
//	if ((m_style_flag & TRIGWNA_SIGENIAS)){
		//zwgrafizoume ta geitonika trigwna tou kokinou trigwnou pou epileksame
		if (!(geitonika_trigwna.empty())){
			
			for (int metr2 = 0; metr2 < geitonika_trigwna.size(); metr2++){
				vvr::Triangle &tr2 = triangles[geitonika_trigwna[metr2]];
				Triangle3D trg3d(
					tr2.v1().x, tr2.v1().y, tr2.v1().z,
					tr2.v2().x, tr2.v2().y, tr2.v2().z,
					tr2.v3().x, tr2.v3().y, tr2.v3().z,
					Colour::green);
				trg3d.draw();

			}
			
		}
		if (!(teleutea_geitonika_trigwna.empty())){
			
			if (teleutos == false){
				for (int metr2 = 0; metr2 < teleutea_geitonika_trigwna.size(); metr2++){
					vvr::Triangle &tr21 = triangles[teleutea_geitonika_trigwna[metr2]];
					Triangle3D trg3d(
						tr21.v1().x, tr21.v1().y, tr21.v1().z,
						tr21.v2().x, tr21.v2().y, tr21.v2().z,
						tr21.v3().x, tr21.v3().y, tr21.v3().z,
						Colour::red);
					trg3d.draw();

				}
			}
//		}
		
		

		//zwgrafizw to katheto epipedo sto meso dianisma normal

		if (m_style_flag & ERWTHMA_4){
			if (!(m_style_flag & PARAMORFWSH_NORMAL)){
				vvr::Colour colPlane(0x41, 0x14, 0xB3);
				float u = 20, v = 20;
				math::vec p0(katheto_epipedo.Point(-u, -v, math::vec(0, 0, 0)));
				math::vec p1(katheto_epipedo.Point(-u, v, math::vec(0, 0, 0)));
				math::vec p2(katheto_epipedo.Point(u, -v, math::vec(0, 0, 0)));
				math::vec p3(katheto_epipedo.Point(u, v, math::vec(0, 0, 0)));
				math2vvr(math::Triangle(p0, p1, p2), colPlane).draw();
				math2vvr(math::Triangle(p2, p1, p3), colPlane).draw();
			}
			
		}



	}

	
	//zwgrafizoume to trigwno tomhs tou Ray me to mesh
	
	if (trigwno > -1){
		
		vvr::Triangle &tr = triangles[trigwno];
		Triangle3D tr3d(
			tr.v1().x, tr.v1().y, tr.v1().z,
			tr.v2().x, tr.v2().y, tr.v2().z,
			tr.v3().x, tr.v3().y, tr.v3().z,
			Colour::red);
		tr3d.draw();
	}
	/*
	for (int v1 = 0; v1 < violations.size(); v1++){

		violations[v1].draw();
	}*/

	for (int v2 = 0; v2 < epipedaa.size(); v2++){
		vvr::Colour colPlane(0x41, 0x14, 0xB3);
		float u = 20, v = 20;
		math::vec p0(epipedaa[v2].Point(-u, -v, math::vec(0, 0, 0)));
		math::vec p1(epipedaa[v2].Point(-u, v, math::vec(0, 0, 0)));
		math::vec p2(epipedaa[v2].Point(u, -v, math::vec(0, 0, 0)));
		math::vec p3(epipedaa[v2].Point(u, v, math::vec(0, 0, 0)));
		math2vvr(math::Triangle(p0, p1, p2), colPlane).draw();
		math2vvr(math::Triangle(p2, p1, p3), colPlane).draw();
	
	}
	
	la1.draw();
	la2.draw();
	la3.draw() ;
		// zwgrafizoume to dihko grafo!

	for (int g = 0; g < dual_gr.size(); g++){
		dual_gr.at(g).draw();

	}
}

int main(int argc, char* argv[])
{
	try {

		return vvr::mainLoop(argc, argv, new Mesh3DScene);
	}
	catch (std::string exc) {
		cerr << exc << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Unknown exception" << endl;
		return 1;
	}
}

//PRWTO ERWTHMA!!!!
//DUAL GRAPH
void dual_graph(Mesh &mesh, Plane &plane, std::vector<vvr::LineSeg3D> &pleures_trigwou, std::vector<vvr::LineSeg3D> &dual_gr){
	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	std::vector<vec> centroids;
	for (int metriths1 = 0; metriths1 < tris.size(); metriths1++) {
		vvr::Triangle &t1 = tris[metriths1];
		bool elenxos1 = false;
		bool idio_trigwno = false;
		for (int metriths2 = 0; metriths2 < tris.size(); metriths2++){
			vvr::Triangle &t2 = tris[metriths2];
			//elenxos mhn exoume parei dio fores to idio trigwno
				if (((fabs(verts[t1.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z)<0.0001)) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && (fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z)<0.0001))) && ((fabs(verts[t1.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z)<0.0001))){

				idio_trigwno = true;
			}
			//ama ta dio tuxaia trigwna tou modelou mas exoun  toulaxiston mia pleura kinh kai oxi kai tis treis(opote anoikoun sto idio trigwno) tote einai geitonika
		
			if ((((fabs(verts[t1.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z)<0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z)<0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z)<0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z)<0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z)<0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z)<0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z)<0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z)<0.00001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z)<0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z)<0.00001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z)<0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z)<0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z)<0.0001)))) && (idio_trigwno == false)){
				//ipologismos Centroid twn dio geitwnikwn trigwnwn kai enwsh tous gia to sxhmatismo tou dual graph

				double c1_x = (t1.v1().x + t1.v2().x + t1.v3().x) / 3;
				double c1_y = (t1.v1().y + t1.v2().y + t1.v3().y) / 3;
				float c1_z = (t1.v1().z + t1.v2().z + t1.v3().z) / 3;


				double c2_x = (t2.v1().x + t2.v2().x + t2.v3().x) / 3;
				double c2_y = (t2.v1().y + t2.v2().y + t2.v3().y) / 3;
				double c2_z = (t2.v1().z + t2.v2().z + t2.v3().z) / 3;


				vec c1;
				c1.x = c1_x;
				c1.y = c1_y;
				c1.z = c1_z;

				vec c2;
				c2.x = c2_x;
				c2.y = c2_y;
				c2.z = c2_z;

				centroids.push_back(c1);
				centroids.push_back(c2);

				LineSeg3D dualGraph(c1.x, c1.y, c1.z, c2.x, c2.y, c2.z, vvr::Colour::red);
				dual_gr.push_back(dualGraph);

			}
		}

		}
}

// DEUTERO ERWTHMA!!!!
//AKTINA EPILOGHS
//TRIGWNA SUGENIAS
void aktina_epiloghs(Mesh &mesh, Ray voh, std::vector<int> &geitonika_trigwna, std::vector<int> &teleutea_geitonika_trigwna){
	float d;
	vec intersectionPoint;
	vec arxiko = voh.pos; //arxiko shmeio tou ray-> ekei pou clickarei arxika o kersoras tou podikiou mou
	std::vector<int> trigwna; //ta trigwna tou mesh pou temnei to Ray
	std::vector<int> dok_trigwna;
	std::vector<vec> shmeia_tomhs;
	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	//vrhskoume ta shmeia tomhs tou Ray me to sugekrimeno trigwno tou modelou mas
	for (int i = 0; i < tris.size(); i++){	
		vvr::Triangle &t = tris[i];
		math::Triangle t1(verts[t.vi1], verts[t.vi2], verts[t.vi3]);
		if (voh.Intersects(t1)){
			voh.Intersects(t1, &d, &intersectionPoint);
			shmeia_tomhs.push_back(intersectionPoint);
			trigwna.push_back(i);
		}
	}

	//a erwthma!!!!
	//psaxnw poio shmeio apo to sinolo shmeiwn tomhs ths aktinas me to adikeimeno mou einai fanero apo thn camera
	//to shmeio me thn mikroterh apostash apo to arxiko shmeio
	if (!shmeia_tomhs.empty()){
		elenxos_akmes = false;
		float min = (shmeia_tomhs.at(0)).Distance(arxiko);
		vec shmeio;
		for (int me = 0; me < shmeia_tomhs.size(); me++){
			float apost = (shmeia_tomhs.at(me)).Distance(arxiko);
			if (min >= apost){
				min = apost;
				shmeio = shmeia_tomhs.at(me);
				trigwno = trigwna[me];

			}
		}
	}
	//b erwthma!!!		
	//upologizw ektos apo to ena trigwno kai ta gitonika tou va8mou sigenias N!!
	// ena trigwno einai gitoniko va8mou sigenias 1 ama exei mia apo tis treis pleures idies kai oxi kai tis treis opote einai to idio trigwno

	std::vector<int> trigwn_geiton_voh;
	std::vector<int> geitonika_trigwna_sugenias1_telika;
	std::vector<int> geitonika_trigwna_sugenias1;

	
		if (!shmeia_tomhs.empty()){
			geitonika_trigwna.clear();
			teleutea_geitonika_trigwna.clear();
			bool teliko = false;
			bool idio_trigwno = false;
			int vath_sugenias = Vathmos_sugenias_N;
			geitonika_trigwna_sugenias1.push_back(trigwno);
			//eksetazw ta trigwna kathe vathmou sigenias xwrista
			for (int metriths3 = 0; metriths3 < vath_sugenias; metriths3++){
				if (metriths3 == (vath_sugenias - 1)){
					teliko = true;
				}
				trigwn_geiton_voh.clear();
				//digrafw ton pinaka

				for (int g = 0; g < geitonika_trigwna_sugenias1.size(); g++){
					trigwn_geiton_voh.push_back(geitonika_trigwna_sugenias1[g]);

				}

				//gia to sigekrimeno vathmo sigenias pairnw ola ta trigwna
				geitonika_trigwna_sugenias1.clear();
				for (int metriths4 = 0; metriths4 < trigwn_geiton_voh.size(); metriths4++){

					
					vvr::Triangle &t3 = tris[trigwn_geiton_voh[metriths4]];
					for (int metriths2 = 0; metriths2 < tris.size(); metriths2++){
						idio_trigwno = false;
						vvr::Triangle &t2 = tris[metriths2];
						//elenxos mhn exoume parei dio fores to idio trigwno
						if (metriths4==metriths2){
							idio_trigwno = true;
						
						}

						if (((fabs(verts[t3.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z)<0.0001)) && ((fabs(verts[t3.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && (fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z)<0.0001))) && ((fabs(verts[t3.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z)<0.0001))){
							idio_trigwno = true;
						}
						//ama ta dio tuxaia trigwna tou modelou mas exoun  toulaxiston mia pleura kinh kai oxi kai tis treis(opote anoikoun sto idio trigwno) tote einai geitonika
						if ((((fabs(verts[t3.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z)<0.0001) && ((fabs(verts[t3.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t3.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z)<0.0001) && ((fabs(verts[t3.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t3.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z)<0.0001) && ((fabs(verts[t3.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z)<0.0001))) || ((fabs(verts[t3.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z)<0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t3.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z)<0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z)<0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z)<0.00001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z)<0.0001))) || ((fabs(verts[t3.vi3].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z)<0.00001) && ((fabs(verts[t3.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t3.vi3].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z)<0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z)<0.0001))) || ((fabs(verts[t3.vi3].x - verts[t2.vi3].x)<0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y)<0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z)<0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi1].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z)<0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x)<0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y)<0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z)<0.0001)))) && (idio_trigwno == false)){
						
							if (teliko == true){
								geitonika_trigwna_sugenias1.push_back(metriths2);
								dok_trigwna.push_back(metriths2);


							}
							else{
								geitonika_trigwna_sugenias1.push_back(metriths2);
								geitonika_trigwna_sugenias1_telika.push_back(metriths2);
								dok_trigwna.push_back(metriths2);
								}


						}
					}
					
				}
				

			}
			//diagrafoume ta trigwna pou exoume parei diplh fora
			if (!dok_trigwna.empty()){
				for (int k1 = 0; k1 < dok_trigwna.size(); k1++){
					bool eisagwgh = true;
					for (int k2 = 0; k2 < geitonika_trigwna.size(); k2++){

						if (dok_trigwna[k1] == geitonika_trigwna[k2]){
							eisagwgh = false;
						}
					}
						if ((dok_trigwna[k1] != trigwno)&&(eisagwgh==true)){
							geitonika_trigwna.push_back(dok_trigwna[k1]);
						
						}
				}
				 
				for (int meg1 = 0; meg1 < geitonika_trigwna.size(); meg1++){
					bool uparxei = false;
					for (int meg2 = 0; meg2 < geitonika_trigwna_sugenias1_telika.size(); meg2++){
						if (geitonika_trigwna[meg1] == geitonika_trigwna_sugenias1_telika[meg2]){
							uparxei = true;
							break;
						}
					}
					if (uparxei == false){
						teleutea_geitonika_trigwna.push_back(geitonika_trigwna[meg1]);
					}
				
				
				}
			}

		}
	


	
	}
//AKTINA EPILOGHS
//KLEISTO VONXO GRAMWN
void akmes_modelou(Mesh &mesh, Ray voh, std::vector<int> &geitonika_trigwna2, std::vector<int> &teleutea_geitonika_trigwna2, std::vector<int> &geitonika_trigwna, std::vector<int> &teleutea_geitonika_trigwna, std::vector<int> & ekswteriko_monopati){
	float d;
	vec intersectionPoint;
	vec arxiko = voh.pos; //arxiko shmeio tou ray-> ekei pou clickarei arxika o kersoras tou podikiou mou
	std::vector<int> trigwna; //ta trigwna tou mesh pou temnei to Ray
	std::vector<int> dok_trigwna;
	std::vector<int> eswterika2;
	std::vector<vec> shmeia_tomhs;
	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	//vrhskoume ta shmeia tomhs tou aksona me to modelo mas
	for (int i = 0; i < tris.size(); i++){
		vvr::Triangle &t = tris[i];
		math::Triangle t1(verts[t.vi1], verts[t.vi2], verts[t.vi3]);
		if (voh.Intersects(t1)){
			voh.Intersects(t1, &d, &intersectionPoint);
			shmeia_tomhs.push_back(intersectionPoint);
			trigwna.push_back(i);
		}
	}

	//a erwthma!!!!
	//psaxnw poio shmeio apo to sinolo shmeiwn tomhs ths aktinas me to adikeimeno mou einai fanero apo thn camera
	//to shmeio me thn mikroterh apostash apo to arxiko shmeio
	if (!shmeia_tomhs.empty()){
		elenxos_akmes = true;
		float min = (shmeia_tomhs.at(0)).Distance(arxiko);
		vec shmeio;
		for (int me = 0; me < shmeia_tomhs.size(); me++){
			float apost = (shmeia_tomhs.at(me)).Distance(arxiko);
			if (min >= apost){
				min = apost;
				shmeio = shmeia_tomhs.at(me);
				trigwno = trigwna[me];

			}
		}
		bool elenxos = false;
		for (int g1 = 0; g1	< geitonika_trigwna2.size(); g1++){
			
			if (geitonika_trigwna2[g1] == trigwno){
				elenxos = true;
			}
			
		}	
		if (elenxos == false){
			geitonika_trigwna2.push_back(trigwno);
		}
		for (int g1 = 0; g1 < geitonika_trigwna2.size();g1++){
			int arithmos_akmwn = 0;
		
			vvr::Triangle &t1 = tris[geitonika_trigwna2[g1]];

			for (int g2 = 0; g2 < geitonika_trigwna2.size(); g2++){
				vvr::Triangle &t2 = tris[geitonika_trigwna2[g2]];
				bool idio_trigwno = false;	
				if (g1==g2){
					idio_trigwno = true;
				}
				if ((((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.00001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.00001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001)))) && (idio_trigwno == false)){
					arithmos_akmwn = arithmos_akmwn + 1;
				}

			}
		
			if (arithmos_akmwn<3){
				teleutea_geitonika_trigwna2.push_back(geitonika_trigwna2[g1]);
			}
			
			

		}
		//dhmiourgia vector mono eswterikwn trigwnwn

		for (int a1 = 0; a1 < geitonika_trigwna2.size(); a1++){
			bool el_es = false;
			for (int a2 = 0; a2 < teleutea_geitonika_trigwna2.size(); a2++){
				if (geitonika_trigwna2[a1] == teleutea_geitonika_trigwna2[a2]){

					el_es = true;
					break;
				}
			}
			if (el_es == false){
				eswterika2.push_back(geitonika_trigwna2[a1]);
			}
		}

		printf("ta eswterika geitonika einai %d\n", eswterika2.size());
		//elenxos gia na doume ama iparxoun trigwna ta opoia dhmiourgoun monopati ekswterikwn trigwnon diladh den exoun vathmo sigenias 1 me kanena eswteriko trigwno
		//auta ta trigwna den ta topothetoume sta dio vectors alla mono se enan 3exwristo gia na ta epe3ergastoume 3exwrista

		for (int g1 = 0; g1 < teleutea_geitonika_trigwna2.size(); g1++){
			bool dhm_monopati = false;
			int ar_akm = 0;
			vvr::Triangle &t1 = tris[teleutea_geitonika_trigwna2[g1]];
			for (int g2 = 0; g2 < eswterika2.size(); g2++){
				vvr::Triangle &t2 = tris[eswterika2[g2]];
				//elenxos uparkshs koinhs akmhs meta3h twn e3wterikwn me ta eswterika geitonika!
					if ((((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.00001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.00001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001))))){
					ar_akm = ar_akm + 1;
					
				}
			}
			if (ar_akm == 0){//pou shmenei oti to trigwno auto anoikei sto 3exwristo monopati
					
				ekswteriko_monopati.push_back(teleutea_geitonika_trigwna2[g1]);
			}
			else{
				teleutea_geitonika_trigwna.push_back(teleutea_geitonika_trigwna2[g1]);
			}

		}
		printf("ta teleutaia geitonika einai %d\n", teleutea_geitonika_trigwna.size());
		printf("to ek3wteriko monopati einai einai %d\n", ekswteriko_monopati.size());

		for (int k1 = 0; k1 <geitonika_trigwna2.size(); k1++){
			bool elenxos_mo = false;
			for (int k2 = 0; k2 < ekswteriko_monopati.size(); k2++){
				if (geitonika_trigwna2[k1] == ekswteriko_monopati[k2]){//den suberimvanoume ston pinaka olwn ton trigwnwn ta trigwna tou monopatiou afou ta epe3rgazomaste 3exwrista
					elenxos_mo = true;
					break;
				}
			}
			if (elenxos_mo == false){
				geitonika_trigwna.push_back(geitonika_trigwna2[k1]);
			}
		}
		printf("ta geitonika einai %d\n", geitonika_trigwna.size());
		
	
	}
}

// TRITO ERWTHMA!!!!
// PIKNOTERO MESH MODELOU

void anadromikh_upodiairesh(Mesh &mesh, std::vector<int> &geitonika_trigwna, std::vector<int> &teleutea_geitonika_trigwna, std::vector<vec> &arxikes_korifes, std::vector<float> &arxika_geitonika, std::vector<int> &nees_korifes, std::vector<int> &ekswteriko_monopati){

	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	std::vector<vvr::Triangle>  tris2 = mesh.getTriangles();
	std::vector<int> nea_geitonika;//exei ta nea eswterika trigwna(ta ipodiairemena)
	std::vector<int> nea_teleutaia_geitonika;//exei ta nea e3wterika trigwna(ta ipodiairemena)
	std::vector<int> new_geitonika_trigwna;//exei ta arxika eswterika trigwna
	std::vector<int> new_teleutaia_geitonika_trigwna;//exei ta arxika e3wterika trigwna
	std::vector<int> new_monopati;
	std::vector<int> ola_shmeia;
	std::vector<int> anikoun_trigwno;
	std::vector<vec> ola_shmeia_eswterika;
	std::vector<vec> ola_shmeia_ekswterika;
	
	int vathmos_ipodiaireshs = Vathmos_ipodiaireshs;
	// a erwthma upodieroume anadromika K fores thn epilegmenh perioxh wste na einai piknotero to mesh tou modelou!!!
	
	//edw pragmatopoihtai h ipodiairesh gia to 3exwristo monopati twn trigwnwn mas!!!

	
	if ((!geitonika_trigwna.empty())||(!ekswteriko_monopati.empty())){

		if (elenxos_akmes == false){
			geitonika_trigwna.push_back(trigwno);
		}
		//apothikeuw ola ta shmeia toy arxikoy modelou, prin thn ipodiairesh
		//xrhsimo gia thn liansh
		for (int arx1 = 0; arx1 < verts.size();arx1++){
			arxikes_korifes.push_back(verts[arx1]);
			arxika_geitonika.push_back(verts[arx1].x);
			arxika_geitonika.push_back(verts[arx1].y);
			arxika_geitonika.push_back(verts[arx1].z);
			
		}
		arxikes_korifes.push_back(verts[trigwno]);
		for (int N = 0; N < vathmos_ipodiaireshs; N++){
			ola_shmeia_eswterika.clear();


	
			for (int mg = 0; mg < geitonika_trigwna.size(); mg++){
				bool uparxei = false;
				for (int mg2 = 0; mg2 < teleutea_geitonika_trigwna.size(); mg2++){
					if (geitonika_trigwna[mg] == teleutea_geitonika_trigwna[mg2]){
						uparxei = true;
						break;
					}
				}
				if (uparxei == false){
					new_geitonika_trigwna.push_back(geitonika_trigwna[mg]);
				}

			}
			for (int g1 = 0; g1 < teleutea_geitonika_trigwna.size(); g1++){
				new_teleutaia_geitonika_trigwna.push_back(teleutea_geitonika_trigwna[g1]);
			}

			
			nea_geitonika.clear();
			nea_teleutaia_geitonika.clear();
			new_monopati.clear();
		
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			for (int l1 = 0; l1 < ekswteriko_monopati.size(); l1++){
				
				vvr::Triangle &tr = tris[ekswteriko_monopati[l1]];
				vec new_shmeio = tr.getCenter();
				verts.push_back(new_shmeio);

				vvr::Triangle neo_trg1(&verts, tr.vi1, tr.vi2, verts.size() - 1);
				vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);
				vvr::Triangle neo_trg3(&verts, tr.vi1, tr.vi3, verts.size() - 1);

				tris.push_back(neo_trg1);
				tris.push_back(neo_trg2);
				tris.push_back(neo_trg3);

				new_monopati.push_back(tris.size() - 3);
				new_monopati.push_back(tris.size() - 2);
				new_monopati.push_back(tris.size() - 1);

			}



			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//diaxwrismos eswterikwn trigwnwn!!!

			for (int metriths1 = 0; metriths1 < new_geitonika_trigwna.size(); metriths1++){

				vvr::Triangle &tr = tris[new_geitonika_trigwna[metriths1]];
				
				vec n1(verts[tr.vi1].x - ((verts[tr.vi1].x - verts[tr.vi2].x) / 2), verts[tr.vi1].y - ((verts[tr.vi1].y - verts[tr.vi2].y) / 2), verts[tr.vi1].z - ((verts[tr.vi1].z - verts[tr.vi2].z) / 2));
				vec n2(verts[tr.vi1].x - ((verts[tr.vi1].x - verts[tr.vi3].x) / 2), verts[tr.vi1].y - ((verts[tr.vi1].y - verts[tr.vi3].y) / 2), verts[tr.vi1].z - ((verts[tr.vi1].z - verts[tr.vi3].z) / 2));
				vec n3(verts[tr.vi2].x - ((verts[tr.vi2].x - verts[tr.vi3].x) / 2), verts[tr.vi2].y - ((verts[tr.vi2].y - verts[tr.vi3].y) / 2), verts[tr.vi2].z - ((verts[tr.vi2].z - verts[tr.vi3].z) / 2));

				

				verts.push_back(n1);
				verts.push_back(n2);
				verts.push_back(n3);

				ola_shmeia_eswterika.push_back(n1);
				ola_shmeia_eswterika.push_back(n2);
				ola_shmeia_eswterika.push_back(n3);

				ola_shmeia.push_back(verts.size()-1);
				ola_shmeia.push_back(verts.size()-2);
				ola_shmeia.push_back(verts.size()-3);

				nees_korifes.push_back(verts.size() - 1);
				nees_korifes.push_back(verts.size() - 2);
				nees_korifes.push_back(verts.size() - 3);


				vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 3);
				vvr::Triangle neo_trg2(&verts, tr.vi2, verts.size() - 3, verts.size() - 1);
				vvr::Triangle neo_trg3(&verts, verts.size() - 2, verts.size() - 3, verts.size() - 1);
				vvr::Triangle neo_trg4(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);


				tris.push_back(neo_trg1);
				tris.push_back(neo_trg2);
				tris.push_back(neo_trg3);
				tris.push_back(neo_trg4);

				nea_geitonika.push_back(tris.size() - 4);
				nea_geitonika.push_back(tris.size() - 3);
				nea_geitonika.push_back(tris.size() - 2);
				nea_geitonika.push_back(tris.size() - 1);

			}
			
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			//diaxwrismos e3wterikwn trigwnwn

			for (int metrk = 0; metrk < new_teleutaia_geitonika_trigwna.size(); metrk++){
				int tomes = 0;
				vvr::Triangle &tr = tris[new_teleutaia_geitonika_trigwna[metrk]];
	
				vec n1(verts[tr.vi1].x - ((verts[tr.vi1].x - verts[tr.vi2].x) / 2), verts[tr.vi1].y - ((verts[tr.vi1].y - verts[tr.vi2].y) / 2), verts[tr.vi1].z - ((verts[tr.vi1].z - verts[tr.vi2].z) / 2));
				vec n2(verts[tr.vi1].x - ((verts[tr.vi1].x - verts[tr.vi3].x) / 2), verts[tr.vi1].y - ((verts[tr.vi1].y - verts[tr.vi3].y) / 2), verts[tr.vi1].z - ((verts[tr.vi1].z - verts[tr.vi3].z) / 2));
				vec n3(verts[tr.vi2].x - ((verts[tr.vi2].x - verts[tr.vi3].x) / 2), verts[tr.vi2].y - ((verts[tr.vi2].y - verts[tr.vi3].y) / 2), verts[tr.vi2].z - ((verts[tr.vi2].z - verts[tr.vi3].z) / 2));
								
				//elenxos gia thnn ipar3h diplwn tomwn:
				for (int f = 0; f < ola_shmeia_eswterika.size(); f++){
					if (fabs(n1.x - ola_shmeia_eswterika[f].x) < 0.0001&&fabs(n1.y - ola_shmeia_eswterika[f].y) < 0.0001&&fabs(n1.z - ola_shmeia_eswterika[f].z) < 0.0001){
						tomes++;
					}
					if (fabs(n2.x - ola_shmeia_eswterika[f].x) < 0.0001&&fabs(n2.y - ola_shmeia_eswterika[f].y) < 0.0001&&fabs(n2.z - ola_shmeia_eswterika[f].z) < 0.0001){
						tomes++;
					}
					if (fabs(n3.x - ola_shmeia_eswterika[f].x) < 0.0001&&fabs(n3.y - ola_shmeia_eswterika[f].y) < 0.0001&&fabs(n3.z - ola_shmeia_eswterika[f].z) < 0.0001){
						tomes++;
					}

				}
				int ni;
				int nea_trigwna = 0;
				int meg_metriths=0;
				int tomes2 = 0;
				for (int f = 0; f < ola_shmeia_eswterika.size(); f++){
					//gia na mhn epanalavw ton diaxwrismo sthn periptwsh twn tomwn
					
					int ap_pl1;
					int ap_pl2;
					int prwt_kor;
					if (fabs(n1.x - ola_shmeia_eswterika[f].x)<0.0001&&fabs(n1.y - ola_shmeia_eswterika[f].y)<0.0001&&fabs(n1.z - ola_shmeia_eswterika[f].z)<0.0001){
						
						verts.push_back(n1);
						nees_korifes.push_back(verts.size() - 1	);
						vvr::Triangle &es_tr = tris[new_geitonika_trigwna[nea_trigwna]];
						//prepei na arxrisw a sigrinw tous diktes se korifes tr.vi1==es_tr.vi1
						if (((fabs(verts[tr.vi1].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi2].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi3].z)<0.0001))){
							
							tomes2++;
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi3, tr.vi1, verts.size() - 1);
									vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi2, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if(tomes==2){
								if (tomes2==2){
										if ((fabs(verts[tr.vi1].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl2].z)<0.0001)){
											vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
											vvr::Triangle neo_trg3(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
											vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi2, verts.size() - 1);
											
											tris.push_back(neo_trg1);
											tris.push_back(neo_trg2);
											tris.push_back(neo_trg3);
											
											nea_teleutaia_geitonika.push_back(tris.size() - 3);
											nea_teleutaia_geitonika.push_back(tris.size() - 2);
											nea_teleutaia_geitonika.push_back(tris.size() - 1);
												
										}
										if ((fabs(verts[tr.vi2].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl2].z)<0.0001)){
											vvr::Triangle neo_trg1(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
											vvr::Triangle neo_trg3(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
											vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi1, verts.size() - 1);

											tris.push_back(neo_trg1);
											tris.push_back(neo_trg2);
											tris.push_back(neo_trg3);

											nea_teleutaia_geitonika.push_back(tris.size() - 3);
											nea_teleutaia_geitonika.push_back(tris.size() - 2);
											nea_teleutaia_geitonika.push_back(tris.size() - 1);

										}
										
									
								}
								else if (tomes2 == 1){
									ni = 1;
									prwt_kor = tr.vi3;
									ap_pl1 = tr.vi1;
									ap_pl2 = tr.vi2;
								}
							}
						}

						if (((fabs(verts[tr.vi1].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi3].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi3].z)<0.0001))){
							
								tomes2++;
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi2, tr.vi1, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
									
									if ((fabs(verts[tr.vi1].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi3].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi1, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									ni = 1;
									prwt_kor = tr.vi2;
									ap_pl1 = tr.vi1;
									ap_pl2 = tr.vi3;
								}
							}
						}
						if (((fabs(verts[tr.vi3].x - verts[es_tr.vi1].x) < 0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi1].y) < 0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi1].z) < 0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi2].x) < 0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi2].y) < 0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi2].z) < 0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi3].x) < 0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi3].y) < 0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi3].z) < 0.0001)) && ((fabs(verts[tr.vi2].x - verts[es_tr.vi1].x) < 0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi1].y) < 0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi1].z) < 0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi2].x) < 0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi2].y) < 0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi2].z) < 0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi3].x) < 0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi3].y) < 0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi3].z) < 0.0001))){
							
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi1, tr.vi2, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi3, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
									
									if ((fabs(verts[tr.vi3].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi2, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi2].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi3, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									ni = 1;
									prwt_kor = tr.vi1;
									ap_pl1 = tr.vi3;
									ap_pl2 = tr.vi2;
								}
							}
						}
				
					}
					if (fabs(n2.x - ola_shmeia_eswterika[f].x)<0.0001&&fabs(n2.y - ola_shmeia_eswterika[f].y)<0.0001&&fabs(n2.z - ola_shmeia_eswterika[f].z)<0.0001){
						
						verts.push_back(n2);
						nees_korifes.push_back(verts.size() - 1);
						tomes2++;
						
						vvr::Triangle &es_tr = tris[new_geitonika_trigwna[nea_trigwna]];
						if (((fabs(verts[tr.vi1].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi2].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi3].z)<0.0001))){
							
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi3, tr.vi1, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi2, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
									
									if ((fabs(verts[tr.vi1].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi2, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi2].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi1, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									prwt_kor = tr.vi3;
									ap_pl1 = tr.vi1;
									ap_pl2 = tr.vi2;
									ni = 2;
								}
							}
						}

						if (((fabs(verts[tr.vi1].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi3].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi3].z)<0.0001))){
							
							if (tomes == 1){
								if (ni == 2){
								}
								vvr::Triangle neo_trg1(&verts, tr.vi2, tr.vi1, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
							}
							if (tomes2 == 2){
								
								if ((fabs(verts[tr.vi1].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl2].z)<0.0001)){
									vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
									vvr::Triangle neo_trg3(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
									vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);

									tris.push_back(neo_trg1);
									tris.push_back(neo_trg2);
									tris.push_back(neo_trg3);

									nea_teleutaia_geitonika.push_back(tris.size() - 3);
									nea_teleutaia_geitonika.push_back(tris.size() - 2);
									nea_teleutaia_geitonika.push_back(tris.size() - 1);

								}
								if ((fabs(verts[tr.vi3].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl2].z)<0.0001)){
									vvr::Triangle neo_trg1(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
									vvr::Triangle neo_trg3(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
									vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi1, verts.size() - 1);

									tris.push_back(neo_trg1);
									tris.push_back(neo_trg2);
									tris.push_back(neo_trg3);

									nea_teleutaia_geitonika.push_back(tris.size() - 3);
									nea_teleutaia_geitonika.push_back(tris.size() - 2);
									nea_teleutaia_geitonika.push_back(tris.size() - 1);

								}
							}
							else if (tomes2 == 1){
								prwt_kor = tr.vi2;
								ap_pl1 = tr.vi1;
								ap_pl2 = tr.vi3;
								ni = 2;
							}
						}
						if (((fabs(verts[tr.vi3].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi2].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi3].z)<0.0001))){							
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi1, tr.vi2, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi3, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
									
									if ((fabs(verts[tr.vi3].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi2, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi2].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi3, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									prwt_kor = tr.vi1;
									ap_pl1 = tr.vi3;
									ap_pl2 = tr.vi2;
									ni = 2;
								}
							}
						}
					}
					if (fabs(n3.x - ola_shmeia_eswterika[f].x)<0.0001&&fabs(n3.y - ola_shmeia_eswterika[f].y)<0.0001&&fabs(n3.z - ola_shmeia_eswterika[f].z)<0.0001){
						tomes2++;
						verts.push_back(n3);
						nees_korifes.push_back(verts.size() - 1);
						
						vvr::Triangle &es_tr = tris[new_geitonika_trigwna[nea_trigwna]];
						if (((fabs(verts[tr.vi1].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi2].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi3].z)<0.0001))){
							
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi3, tr.vi1, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi2, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
									
									if ((fabs(verts[tr.vi1].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi2, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi2].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi3, tr.vi1, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									prwt_kor = tr.vi3;
									ap_pl1 = tr.vi1;
									ap_pl2 = tr.vi2;
									ni = 3;
								}
							}
						}

						if (((fabs(verts[tr.vi1].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi1].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi1].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi3].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi3].z)<0.0001))){
							
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi2, tr.vi1, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
									
									if ((fabs(verts[tr.vi1].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi1].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi1].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi1].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi3, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi3].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi2, tr.vi1, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									prwt_kor = tr.vi2;
									ap_pl1 = tr.vi1;
									ap_pl2 = tr.vi3;
									ni = 3;
								}
							}
						}
						if (((fabs(verts[tr.vi3].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi3].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi3].z - verts[es_tr.vi3].z)<0.0001)) && ((fabs(verts[tr.vi2].x - verts[es_tr.vi1].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi1].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi2].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi2].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi2].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[es_tr.vi3].x)<0.0001 && fabs(verts[tr.vi2].y - verts[es_tr.vi3].y)<0.0001 && fabs(verts[tr.vi2].z - verts[es_tr.vi3].z)<0.0001))){
						
							if (tomes == 1){
								vvr::Triangle neo_trg1(&verts, tr.vi1, tr.vi2, verts.size() - 1);
								vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi3, verts.size() - 1);

								tris.push_back(neo_trg1);
								tris.push_back(neo_trg2);

								nea_teleutaia_geitonika.push_back(tris.size() - 2);
								nea_teleutaia_geitonika.push_back(tris.size() - 1);
							}
							else if (tomes == 2){
								
								if (tomes2 == 2){
							
									if ((fabs(verts[tr.vi3].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi3].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi3].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi3].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi3, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi2, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
									if ((fabs(verts[tr.vi2].x - verts[ap_pl1].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl1].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl1].z)<0.0001) || (fabs(verts[tr.vi2].x - verts[ap_pl2].x)<0.0001&&fabs(verts[tr.vi2].y - verts[ap_pl2].y)<0.0001&&fabs(verts[tr.vi2].z - verts[ap_pl2].z)<0.0001)){
										vvr::Triangle neo_trg1(&verts, tr.vi2, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg3(&verts, tr.vi1, verts.size() - 2, verts.size() - 1);
										vvr::Triangle neo_trg2(&verts, tr.vi1, tr.vi3, verts.size() - 1);

										tris.push_back(neo_trg1);
										tris.push_back(neo_trg2);
										tris.push_back(neo_trg3);

										nea_teleutaia_geitonika.push_back(tris.size() - 3);
										nea_teleutaia_geitonika.push_back(tris.size() - 2);
										nea_teleutaia_geitonika.push_back(tris.size() - 1);

									}
								}
								else if (tomes2 == 1){
									prwt_kor = tr.vi1;
									ap_pl1 = tr.vi3;
									ap_pl2 = tr.vi2;
									ni = 3;
								}
							}
						}
					}
					meg_metriths++;
					if (meg_metriths == 3){
						meg_metriths = 0;
						
						nea_trigwna ++;
					}
				}
				

			}

			

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			
			//kai twra prepei na diagrayw ta arxika trigwna

			// auta pou sxetizodai me to e3wteriko monopati
			

			for (int t_k = 0; t_k < ekswteriko_monopati.size(); t_k++){
				tris.erase(tris.begin() + ekswteriko_monopati[t_k]);
				for (int metriths2 = 0; metriths2 < ekswteriko_monopati.size(); metriths2++){
					if (ekswteriko_monopati[t_k] < ekswteriko_monopati[metriths2]){
						ekswteriko_monopati[metriths2] = ekswteriko_monopati[metriths2] - 1;
					}
				}

				for (int metriths2 = 0; metriths2 < new_monopati.size(); metriths2++){
					if (ekswteriko_monopati[t_k] < new_monopati[metriths2]){
						new_monopati[metriths2] = new_monopati[metriths2] - 1;
					}
				}
				for (int metriths2 = 0; metriths2 < new_teleutaia_geitonika_trigwna.size(); metriths2++){
					if (ekswteriko_monopati[t_k] < new_teleutaia_geitonika_trigwna[metriths2]){
						new_teleutaia_geitonika_trigwna[metriths2] = new_teleutaia_geitonika_trigwna[metriths2] - 1;
					}
				}
				for (int metriths3 = 0; metriths3 < new_geitonika_trigwna.size(); metriths3++){
					if (ekswteriko_monopati[t_k] < new_geitonika_trigwna[metriths3]){
						new_geitonika_trigwna[metriths3] = new_geitonika_trigwna[metriths3] - 1;
					}
				}

				for (int metriths4 = 0; metriths4 < nea_teleutaia_geitonika.size(); metriths4++){
					if (ekswteriko_monopati[t_k] < nea_teleutaia_geitonika[metriths4]){
						nea_teleutaia_geitonika[metriths4] = nea_teleutaia_geitonika[metriths4] - 1;
					}
				}

				for (int metriths4 = 0; metriths4 < nea_geitonika.size(); metriths4++){
					if (ekswteriko_monopati[t_k] < nea_geitonika[metriths4]){
						nea_geitonika[metriths4] = nea_geitonika[metriths4] - 1;
					}
				}
			}

			
			//auta pou sxetizodai me ta arxika e3werika

			for (int me1 = 0; me1 < new_teleutaia_geitonika_trigwna.size(); me1++){
				tris.erase(tris.begin() + new_teleutaia_geitonika_trigwna[me1]);

				for (int metriths2 = 0; metriths2 < new_teleutaia_geitonika_trigwna.size(); metriths2++){
					if (new_teleutaia_geitonika_trigwna[me1] < new_teleutaia_geitonika_trigwna[metriths2]){
						new_teleutaia_geitonika_trigwna[metriths2] = new_teleutaia_geitonika_trigwna[metriths2] - 1;
					}
				}
				for (int metriths3 = 0; metriths3 < new_geitonika_trigwna.size(); metriths3++){
					if (new_teleutaia_geitonika_trigwna[me1] < new_geitonika_trigwna[metriths3]){
						new_geitonika_trigwna[metriths3] = new_geitonika_trigwna[metriths3] - 1;
					}
				}

				for (int metriths4 = 0; metriths4 < nea_teleutaia_geitonika.size(); metriths4++){
					if (new_teleutaia_geitonika_trigwna[me1] < nea_teleutaia_geitonika[metriths4]){
						nea_teleutaia_geitonika[metriths4] = nea_teleutaia_geitonika[metriths4] - 1;
					}
				}

				for (int metriths4 = 0; metriths4 < nea_geitonika.size(); metriths4++){
					if (new_teleutaia_geitonika_trigwna[me1] < nea_geitonika[metriths4]){
						nea_geitonika[metriths4] = nea_geitonika[metriths4] - 1;
					}
				}
				for (int metriths5 = 0; metriths5 < new_monopati.size(); metriths5++){
					if (new_teleutaia_geitonika_trigwna[me1] < new_monopati[metriths5]){
						new_monopati[metriths5] = new_monopati[metriths5] - 1;
					}
				}

			}
				//auta pou sxetizodai me ta arxika eswterika
			
			for (int me1 = 0; me1 <new_geitonika_trigwna.size(); me1++){
				tris.erase(tris.begin() + new_geitonika_trigwna[me1]);

				for (int metriths2 = 0; metriths2 < new_geitonika_trigwna.size(); metriths2++){
					if (new_geitonika_trigwna[me1] < new_geitonika_trigwna[metriths2]){
						new_geitonika_trigwna[metriths2] = new_geitonika_trigwna[metriths2] - 1;
					}
				}
				for (int metriths3 = 0; metriths3 <new_teleutaia_geitonika_trigwna.size(); metriths3++){
					if (new_geitonika_trigwna[me1] < new_teleutaia_geitonika_trigwna[metriths3]){
						new_teleutaia_geitonika_trigwna[metriths3] = new_teleutaia_geitonika_trigwna[metriths3] - 1;
					}
				}

				for (int metriths4 = 0; metriths4 < nea_geitonika.size(); metriths4++){
					if (new_geitonika_trigwna[me1] < nea_geitonika[metriths4]){
						nea_geitonika[metriths4] = nea_geitonika[metriths4] - 1;
					}
					
				}
				
				for (int metriths4 = 0; metriths4 < nea_teleutaia_geitonika.size(); metriths4++){
					if (new_geitonika_trigwna[me1] < nea_teleutaia_geitonika[metriths4]){
						nea_teleutaia_geitonika[metriths4] = nea_teleutaia_geitonika[metriths4] - 1;
					}

				}
				for (int metriths5 = 0; metriths5 < new_monopati.size(); metriths5++){
					if (new_geitonika_trigwna[me1] < new_monopati[metriths5]){
						new_monopati[metriths5] = new_monopati[metriths5] - 1;
					}
				}

			}
			new_geitonika_trigwna.clear();
			new_teleutaia_geitonika_trigwna.clear();
			teleutea_geitonika_trigwna.clear();
			geitonika_trigwna.clear();
			ekswteriko_monopati.clear();

			//kai twra prepei na ananewsw tous palious pinakes me thn allagh tou mesh-> prosthiki epipleon shmeiwn
			 
			for (int g2 = 0; g2 < nea_geitonika.size(); g2++){
				geitonika_trigwna.push_back(nea_geitonika[g2]);


			}
			for (int g2 = 0; g2 < nea_teleutaia_geitonika.size(); g2++){
				geitonika_trigwna.push_back(nea_teleutaia_geitonika[g2]);
				teleutea_geitonika_trigwna.push_back(nea_teleutaia_geitonika[g2]);
			}

			for (int g2 = 0; g2 < new_monopati.size(); g2++){
				ekswteriko_monopati.push_back(new_monopati[g2]);
			}	

			//edw 8a xwrisw gia ta nea sxhmatismena trigwna ta e3wterika giati metavalwde analoga me thn trigwnopoihsh kai ta geitonika
			for (int g3 = 0; g3 < teleutea_geitonika_trigwna.size(); g3++){
				vvr::Triangle &t3 = tris[teleutea_geitonika_trigwna[g3]];
				int mell = 0;
				for (int g4 = 0; g4 < geitonika_trigwna.size(); g4++){
					if (geitonika_trigwna[g4]!=teleutea_geitonika_trigwna[g3]){
						
						vvr::Triangle &t2 = tris[geitonika_trigwna[g4]];
						if (((fabs(verts[t3.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t3.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t3.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t3.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t3.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t3.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t3.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t3.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t3.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z) < 0.00001) || (fabs(verts[t3.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t3.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi1].z) < 0.00001) && ((fabs(verts[t3.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t3.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t3.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t3.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t3.vi3].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t3.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t3.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t3.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t3.vi2].z - verts[t2.vi2].z) < 0.0001)))){
							mell++;
						}
					}
				}
				//ama exei kai tis treis ppleures tou kines vgenei apo ton pinaka twn e3wterikwn trigwnwn kai bainei ston pinaka twn eswterikwn
				if (mell == 3){
					for (int an = g3 + 1; an < teleutea_geitonika_trigwna.size(); an++){
						teleutea_geitonika_trigwna[an - 1] = teleutea_geitonika_trigwna[an];
					}
					teleutea_geitonika_trigwna.erase(teleutea_geitonika_trigwna.begin()+(teleutea_geitonika_trigwna.size()-1));
					g3 = g3 - 1;
				}
			
			}
		}

		
	}
}

//TRITO ERWTHMA!!!!
//LIANSH PERIOXHS

void liansh_perioxhs(Mesh &mesh, std::vector<int> &geitonika_trigwna, std::vector<vec> &arxikes_korifes, std::vector<float> &arxika_geitonika, std::vector<int> &nees_korifes){

	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	std::vector<int> grammh_pinaka;
	std::vector<int> katw_monadieos;
	
	std::vector<int> sindesh_korifwn;

	//epeidh to modelo borei na mhn einai teleio
	for (int l = 0; l < verts.size(); l++){
		for (int h = 0; h < verts.size(); h++){
			if (verts[l].Equals(verts[h])){
				sindesh_korifwn.push_back(l);
				sindesh_korifwn.push_back(h);
			}
		}
	}

	const int	megethos_pinaka = verts.size();
	const int m = arxikes_korifes.size();

	Eigen::MatrixXd L(megethos_pinaka + m, megethos_pinaka);

	Eigen::VectorXd Pinakas_d(megethos_pinaka + m);
	Eigen::VectorXd Pinakas_d2(megethos_pinaka + m);
	Eigen::VectorXd Pinakas_d3(megethos_pinaka + m);


	Eigen::MatrixXd L_K(megethos_pinaka, megethos_pinaka);
	Eigen::MatrixXd A(megethos_pinaka, megethos_pinaka);
	Eigen::MatrixXd D(megethos_pinaka, megethos_pinaka);
	Eigen::MatrixXd monad(megethos_pinaka, megethos_pinaka);
	std::vector<vec> el_kor;


	for (int r = 0; r < megethos_pinaka; r++){
		for (int r2 = 0; r2 < megethos_pinaka; r2++){
			if (r == r2){
				monad(r, r) = 1;
			}
			else{
				monad(r, r2) = 0;
			}
			A(r, r2) = 0;
			D(r, r2) = 0;
		}
	}


	for (int kor = 0; kor < megethos_pinaka; kor++){
		//prepei na vrw kathe korifh se posa trigwna anoikei!! 
		//se ka8e trigwno pou anoikei ka8e korifh exei ws amesa sindedemenes korifes tis dio alles korifes tou trigwnou!!
		vec e3_korif = verts[kor];

		bool elen = false;
		el_kor.push_back(verts[kor]);
		for (int t = 0; t < tris.size(); t++){
			vvr::Triangle &trigwno = tris[t];

			if (((fabs(e3_korif.x - verts[trigwno.vi1].x)<0.0001) && (fabs(e3_korif.y - verts[trigwno.vi1].y)<0.0001) && (fabs(e3_korif.z - verts[trigwno.vi1].z)<0.0001)) && elen == false){
				int me11 = 0;
				A(kor, trigwno.vi2) = 1;
				A(kor, trigwno.vi3) = 1;
					
				}


			
			if (((fabs(e3_korif.x - verts[trigwno.vi2].x)<0.0001) && (fabs(e3_korif.y - verts[trigwno.vi2].y)<0.0001) && (fabs(e3_korif.z - verts[trigwno.vi2].z)<0.0001)) && elen == false){
				A(kor, trigwno.vi1) = 1;
				A(kor, trigwno.vi3) = 1;
			}
			if (((fabs(e3_korif.x - verts[trigwno.vi3].x)<0.0001) && (fabs(e3_korif.y - verts[trigwno.vi3].y)<0.0001) && (fabs(e3_korif.z - verts[trigwno.vi3].z)<0.0001)) && elen == false){
				A(kor, trigwno.vi2) = 1;
				A(kor, trigwno.vi1) = 1;
			}
		}

		//A(kor, kor) = 1;
		//siblirwnw ta diagwnia stoixeia tou L pinaka
		int ar_koin_kor = 0;
		for (int mee = 0; mee < megethos_pinaka; mee++){
			if (A(kor, mee) == 1){
				ar_koin_kor = ar_koin_kor + 1;
			}

		}


		D(kor, kor) = (ar_koin_kor);


	}

	printf("dgmiourgei ton L pinaka\n");


	//std::cout << D << std::endl;

	A = (D.inverse())*A;
	printf("upologizeo ton adistrofo\n");

	L_K = monad - A;

	for (int r = 0; r < megethos_pinaka + m; r++){
		Pinakas_d(r) = 0;
		Pinakas_d2(r) = 0;
		Pinakas_d3(r) = 0;
	}


	for (int r = 0; r < megethos_pinaka + m; r++){
		for (int r2 = 0; r2 < megethos_pinaka; r2++){
			L(r, r2) = 0;
		}
	}

	for (int ki1 = 0; ki1 < megethos_pinaka; ki1++){
		for (int ki2 = 0; ki2 < megethos_pinaka; ki2++){
			L(ki1, ki2) = L_K(ki1, ki2);

		}

	}

	int me = 0;
	for (int k2 = 0; k2 < arxika_geitonika.size(); k2++){
		Pinakas_d(megethos_pinaka + me) = arxika_geitonika[k2];
		Pinakas_d2(megethos_pinaka + me) = arxika_geitonika[k2 + 1];
		Pinakas_d3(megethos_pinaka + me) = arxika_geitonika[k2 + 2];
		L(megethos_pinaka + me, me) = 10;
		
		me = me + 1;
		k2 = k2 + 2;
	}

	//vazw gia varos W=10


	Pinakas_d = Pinakas_d * 10;
	Pinakas_d2 = Pinakas_d2 * 10;
	Pinakas_d3 = Pinakas_d3 * 10;

	//	std::cout << Pinakas_d << std::endl;

	printf("BENEI PRIN THN EPILISH TWN LEAST SQUEARS \n");

	Eigen::VectorXd x(megethos_pinaka);
	Eigen::VectorXd y(megethos_pinaka);
	Eigen::VectorXd z(megethos_pinaka);


	x = (L.transpose() * L).inverse()*(L.transpose() * Pinakas_d);
	y = (L.transpose() * L).inverse()*(L.transpose() * Pinakas_d2);
	z = (L.transpose() * L).inverse()*(L.transpose() * Pinakas_d3);

	std::vector<float> pinak1;
	for (int k = 0; k < x.size(); k++){
		pinak1.push_back(x[k]);
	}
	for (int k = 0; k < pinak1.size(); k++){
		verts[k].x = pinak1[k];
	

	}

	std::vector<float> pinak2;
	for (int k = 0; k < y.size(); k++){
		pinak2.push_back(y[k]);
	}
	for (int k = 0; k < pinak2.size(); k++){
				verts[k].y = pinak2[k];
		
	}

	std::vector<float> pinak3;
	for (int k = 0; k < z.size(); k++){
		pinak3.push_back(z[k]);
	}
	for (int k = 0; k < pinak3.size(); k++){
				verts[k].z = pinak3[k];
		
	}

	for (int g = 0; g < sindesh_korifwn.size(); g=g+2){
		verts[sindesh_korifwn[g]] = verts[sindesh_korifwn[g + 1]];
	}

	printf("H diadikasia teleiwse\n");
	
}

// TETARTO ERWTHMA!!!!
//MESO NORMAL DIANISMA

void meso_normal(Mesh &mesh,std::vector<int> &geitonika_trigwna){
	std::vector<vec> gwnies_geitonikwn;
	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	
	//a erwthma!!
	//gia na vrw to meso normal dianisma prosthetw dianismatika ola ta normals kai ta dierw dia tou plhthous tous
	std::cout << "ipologismos mesou normal dianismatos" << std::endl;
	m_norm = vec(0, 0, 0);
	if (!geitonika_trigwna.empty()){
		for (int g2 = 0; g2 < geitonika_trigwna.size(); g2++){
			vvr::Triangle &m_n = tris[geitonika_trigwna[g2]];
			vec n1 = m_n.getNormal();

			m_norm.x = m_norm.x + n1.x;
			m_norm.y = m_norm.y + n1.y;
			m_norm.z = m_norm.z + n1.z;


		}

		m_norm.Normalize();

		//b erwthma!!
		//epipedo katheto sto meso normal kai exei tis mises twn epilegmenwn korifwn apo th mia pleura kai tis alles mises apo thn allh

		//upologismos shmeiou epifaneias epilegmenwn korifwn pou to epipedo pou pernaei apo auth exei tis mises korifes 
		//apo th mia pleura kai tis alles mises apo thn allh!!

		//arxika upologizw oles tis mones korifes twn geitonikwn trigwnwn


		std::vector<vec> mones_korifes_geitonikwn2;
		std::vector<vec> korifes_geitonikwn2;
		int elenxos;
		int apotelesma1;
		int auto_pou_theloume;
		int apotelesma2;
		

		for (int t = 0; t < geitonika_trigwna.size(); t++){
			korifes_geitonikwn2.push_back(verts[tris[geitonika_trigwna[t]].vi1]);
			korifes_geitonikwn2.push_back(verts[tris[geitonika_trigwna[t]].vi2]);
			korifes_geitonikwn2.push_back(verts[tris[geitonika_trigwna[t]].vi3]);
		}	

		for (int g = 0; g < korifes_geitonikwn2.size(); g++){

			bool elenxos = false;
			for (int h = 0; h < mones_korifes_geitonikwn2.size(); h++){
				if (korifes_geitonikwn2[g].Equals(mones_korifes_geitonikwn2[h])){

					elenxos = true;
					break;
				}
			}
			if (elenxos == false){
				mones_korifes_geitonikwn2.push_back(korifes_geitonikwn2[g]);
			}
		}
		int sinolikes_korifes = mones_korifes_geitonikwn2.size();
		

		printf("ARXIKA EXOUME %d\n", mones_korifes_geitonikwn2.size());
		vec apo = tris[geitonika_trigwna[0]].getCenter();
		Plane epipedo_elenxou = Plane(apo, m_norm);
		if (sinolikes_korifes % 2 != 0){
			printf("perith diadikasia!!!\n");
			int plithos_korifwn = sinolikes_korifes / 2;
			int megisth;
			int meg_plithos = 50000000000000000;
			int metriths_korifwnt;
			for (int g = 0; g < mones_korifes_geitonikwn2.size(); g++){
				apo = mones_korifes_geitonikwn2[g];
				epipedo_elenxou = Plane(apo, m_norm);

				int metriths_korifwn = 0;
				for (int k = 0; k < mones_korifes_geitonikwn2.size(); k++){
					if (epipedo_elenxou.IsOnPositiveSide(mones_korifes_geitonikwn2[k])){
						metriths_korifwn = metriths_korifwn + 1;
					}
				}

				if (meg_plithos >= abs(metriths_korifwn - plithos_korifwn)){
					megisth = g;
					meg_plithos = abs(metriths_korifwn - plithos_korifwn);
					metriths_korifwnt = metriths_korifwn;
				}

			}
 			apo = mones_korifes_geitonikwn2[megisth];
			epipedo_elenxou = Plane(apo, m_norm);

			auto_pou_theloume = plithos_korifwn;
			apotelesma1 = metriths_korifwnt;

			printf("to plhthos twn thetikwn shmeiwn theloume na einai %d\n", plithos_korifwn);
			printf("oi thetikes korifes einai %d\n", metriths_korifwnt);
		}

		else{
			printf("artia diadikasia\n");
			std::vector<vec> kedrika;
			
			for (int t = 0; t < geitonika_trigwna.size(); t++){
				
				kedrika.push_back(tris[geitonika_trigwna[t]].getCenter());
			}
			int plithos_korifwn = sinolikes_korifes / 2;


			int megisth;
			int meg_plithos = 50000000000000000;
			int metriths_korifwnt;
			for (int g = 0; g < kedrika.size(); g++){
				apo = kedrika[g];
				epipedo_elenxou = Plane(apo, m_norm);

				int metriths_korifwn = 0;
				for (int k = 0; k < mones_korifes_geitonikwn2.size(); k++){
					if (epipedo_elenxou.IsOnPositiveSide(mones_korifes_geitonikwn2[k])){
						metriths_korifwn = metriths_korifwn + 1;
					}
				}

				if (meg_plithos >= abs(metriths_korifwn - plithos_korifwn)){
					megisth = g;
					meg_plithos = abs(metriths_korifwn - plithos_korifwn);
					metriths_korifwnt = metriths_korifwn;
				}

			}
			apo = kedrika[megisth];
			epipedo_elenxou = Plane(apo, m_norm);

			auto_pou_theloume = plithos_korifwn;
			apotelesma1 = metriths_korifwnt;

			auto_pou_theloume = plithos_korifwn;
			apotelesma2 = metriths_korifwnt;

			printf("to plhthos twn thetikwn shmeiwn theloume na einai %d\n", plithos_korifwn);
			printf("oi thetikes korifes einai %d\n", metriths_korifwnt);
			
		
		}
		
		int allo = 0;
		int allo2 = 0;
		bool allagh = false;
		float metavolh = epipedo_elenxou.d;

		int arx = abs(apotelesma2 - auto_pou_theloume);
		while((apotelesma1-auto_pou_theloume)!=0){
			
			
			
			float idio = metavolh;
			while ((arx-allo) >= 0){
				
				metavolh = metavolh + 0.000001;

				epipedo_elenxou.d = metavolh;

				int metriths_korifwn = 0;
				for (int k = 0; k < mones_korifes_geitonikwn2.size(); k++){
					if (epipedo_elenxou.IsOnPositiveSide(mones_korifes_geitonikwn2[k])){
						metriths_korifwn = metriths_korifwn + 1;
						apotelesma1 = metriths_korifwn;
						
					}
				}
		
				allo = abs(apotelesma1 - auto_pou_theloume);
				if (apotelesma1 - auto_pou_theloume == 0){
					allagh = true;
				
					break;
				}
				
			}
			
			metavolh = idio;
			while (((arx-allo2) >= 0)&&allagh==false){
				
				metavolh = metavolh - 0.000001;

				epipedo_elenxou.d = metavolh;

				int metriths_korifwn = 0;
				for (int k = 0; k < mones_korifes_geitonikwn2.size(); k++){
					if (epipedo_elenxou.IsOnPositiveSide(mones_korifes_geitonikwn2[k])){
						metriths_korifwn = metriths_korifwn + 1;
						apotelesma1 = metriths_korifwn;
					}
				}
		
				allo2 = abs(apotelesma1 - auto_pou_theloume);
				if (apotelesma1 - auto_pou_theloume == 0){
					allagh = true;
					break;
				}
			}
			
			break;

		}
		
		if (allagh == false){
			epipedo_elenxou.d=metavolh;

			int metriths_korifwn = 0;
			for (int k = 0; k < mones_korifes_geitonikwn2.size(); k++){
				if (epipedo_elenxou.IsOnPositiveSide(mones_korifes_geitonikwn2[k])){
					metriths_korifwn = metriths_korifwn + 1;
					apotelesma1 = metriths_korifwn;
				}
			}
		}
		printf("oi thetikes korifes meta thn epeksergasia einai %d\n", apotelesma1);
		
		katheto_epipedo = epipedo_elenxou;
	}
}

//PEMTO ERWTHMA!!!
//PARAMORFWSH EPILEGMENHS PERIOXHS	

//dhmiourgia twn upoperioxwn panw apo to epipedo kai katw apo to epipedo oi opoies 8a paramorfo8oun sth sinexeia 
void dimiourgia_upoperioxwn(Mesh &mesh, std::vector<int> &geitonika_trigwna, Plane &katheto_epipedo,std::vector<int> &panw_korifes, std::vector<int> &katw_korifes){
	
	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	panw_korifes.clear();
	katw_korifes.clear();

	//arxika thelw na apothikeusw se dio pinakes tis dio omades korifwn apo thn epilegmenh perioxh pou xwrizei to epipedo mas
	if (!geitonika_trigwna.empty()){
		vector < int> ksana;
		int t_size = geitonika_trigwna.size();



		bool ta4 = false;
		bool ta5 = false;
		bool ta6 = false;

		for (int i = 0; i < geitonika_trigwna.size(); i++) {

			vvr::Triangle &t = tris[geitonika_trigwna[i]];

			float a = katheto_epipedo.normal.x;
			float b = katheto_epipedo.normal.y;
			float c = katheto_epipedo.normal.z;
			float d = katheto_epipedo.d;

			

			vec v1 = t.v1();
			vec v2 = t.v2();
			vec v3 = t.v3();

			float t1 = a*v1.x + b*v1.y + c*v1.z - d;
			float t2 = a*v2.x + b*v2.y + c*v2.z - d;
			float t3 = a*v3.x + b*v3.y + c*v3.z - d;

			if (i == 0){
				ksana.push_back(t.vi1);
				ksana.push_back(t.vi2);
				ksana.push_back(t.vi3);
			}
			for (int me2 = 0; me2 < ksana.size(); me2++){
				if (t.vi1 == ksana[me2]){
					ta4 = true;

				}
				if (t.vi2 == ksana[me2]){
					ta5 = true;
				}
				if (t.vi3 == ksana[me2]){
					ta6 = true;
				}
			}


			if ((t1*t2 <= 0) || (t1*t3 <= 0) || (t3*t2 <= 0)){

				if (t1 > 0){
					if (ta4 == false){
						panw_korifes.push_back(t.vi1);
						ksana.push_back(t.vi1);

					}
				}
				else{
					if (ta4 == false){
						katw_korifes.push_back(t.vi1);
						ksana.push_back(t.vi1);
					}
				}
				if (t2 > 0){
					if (ta5 == false){
						panw_korifes.push_back(t.vi2);
						ksana.push_back(t.vi2);

					}
				}
				else{
					if (ta5 == false){
						katw_korifes.push_back(t.vi2);
						ksana.push_back(t.vi2);
					}
				}

				if (t3 > 0){
					if (ta6 == false){
						panw_korifes.push_back(t.vi3);
						ksana.push_back(t.vi3);

					}
				}
				else{
					if (ta6 == false){
						katw_korifes.push_back(t.vi3);
						ksana.push_back(t.vi3);
					}
				}

				ta4 = false;
				ta5 = false;
				ta6 = false;
			}


			if ((t1 > 0) && (t2 > 0) && (t3 > 0)){
				
				if (ta4 == false){
					panw_korifes.push_back(t.vi1);
					ksana.push_back(t.vi1);
					
				}
				if (ta5 == false){
					panw_korifes.push_back(t.vi2);
					ksana.push_back(t.vi2);
					
				}
				if (ta6 == false){
					panw_korifes.push_back(t.vi3);
					ksana.push_back(t.vi3);

				}

				ta4 = false;
				ta5 = false;
				ta6 = false;

			}
			else if ((t1 < 0) && (t2 < 0) && (t3 < 0)){

				if (ta4 == false){
					katw_korifes.push_back(t.vi1);
					
					ksana.push_back(t.vi1);
				}
				if (ta5 == false){
					katw_korifes.push_back(t.vi2);
					ksana.push_back(t.vi2);
					
				}
				if (ta6 == false){
					katw_korifes.push_back(t.vi3);
					ksana.push_back(t.vi3);
					
				}

				ta4 = false;
				ta5 = false;
				ta6 = false;

			}
			
		}
		for (int p1 = 0; p1 < panw_korifes.size(); p1++){
			kedr_mazas = kedr_mazas + verts[panw_korifes[p1]];
			
		}
		for (int p1 = 0; p1 < katw_korifes.size(); p1++){
			kedr_mazas = kedr_mazas + verts[katw_korifes[p1]];

		}
		kedr_mazas = kedr_mazas / (panw_korifes.size() + katw_korifes.size());
	}
}

//paramorfwsh epilegmenhs perioxhs me th voh8eia tou moise
void diaxwrismos_epipedou_ep(Mesh &mesh, std::vector<int> &geitonika_trigwna, Plane &katheto_epipedo, std::vector<int> &panw_korifes, std::vector<int> &katw_korifes,int dir){

	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	if (!geitonika_trigwna.empty()){
		//prwto erwtha!!!
		//paramorfwsh vash tou epipedou

		for (int g1 = 0; g1 < katw_korifes.size(); g1++){
			verts[katw_korifes[g1]] = verts[katw_korifes[g1]] - (dir * 5)*katheto_epipedo.normal;

		}
		for (int g2 = 0; g2 < panw_korifes.size(); g2++){
			verts[panw_korifes[g2]] = verts[panw_korifes[g2]] + (dir * 5)*katheto_epipedo.normal;
		}
	}
		
}
void diaxwrismos_epipedou_nor(Mesh &mesh, std::vector<int> &geitonika_trigwna, Plane &katheto_epipedo, std::vector<int> &panw_korifes, std::vector<int> &katw_korifes, int dir){

	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	if (!geitonika_trigwna.empty()){
		
		for (int g1 = 0; g1 < katw_korifes.size(); g1++){
			
			vec shmeio;
			
			shmeio =  verts[katw_korifes[g1]]-kedr_mazas ;
			vec provolh = shmeio.ProjectTo(m_norm);
			
			vec teliko;
			teliko.x =provolh.x - shmeio.x;
			teliko.y =provolh.y - shmeio.y;
			teliko.z = provolh.z- shmeio.z;
			
			teliko.Normalize();

			verts[katw_korifes[g1]] = verts[katw_korifes[g1]] -  0.5*dir*teliko;
		}
		for (int g2 = 0; g2 < panw_korifes.size(); g2++){
			vec shmeio2;
			
			shmeio2 = verts[panw_korifes[g2]]-kedr_mazas ;
			vec provolh2 = shmeio2.ProjectTo(m_norm);

			vec teliko2;
			teliko2.x = provolh2.x - shmeio2.x;
			teliko2.y = provolh2.y - shmeio2.y;
			teliko2.z = provolh2.z - shmeio2.z;
			teliko2.Normalize();
			
			verts[panw_korifes[g2]] = verts[panw_korifes[g2]] - 0.5* dir*teliko2;

		}

	}
	

}
void epanatrigwnopoihsh(Mesh &mesh, std::vector<int> &geitonika_trigwna){
	std::cout << "ekteleite h epanatrigwnopoihsh " << std::endl;
	std::vector<vec> &verts = mesh.getVertices();
	std::vector<vvr::Triangle>  &tris = mesh.getTriangles();
	std::vector<int> trigwna_metavolhs;
	std::vector<int> korifes_paraviashs;
	std::vector<Sphere> sfaires_paraviashs;
	if (!geitonika_trigwna.empty()){
		teleutos = true;
		geitonika_trigwna.push_back(trigwno);
		int arithmos_epan = 0;
		bool paraviaseis = true;
		while (paraviaseis == true && arithmos_epan < 20){
			violations.clear();
			trigwna_metavolhs.clear();
			sfaires_paraviashs.clear();
			for (int k1 = 0; k1 < geitonika_trigwna.size(); k1++){
				vvr::Triangle &t = tris[geitonika_trigwna[k1]];

				vec p1 = verts[t.vi1];
				vec p2 = verts[t.vi2];
				vec p3 = verts[t.vi3];

				vec meso_1 = (p1 + p2) / 2;
				vec meso_2 = (p1 + p3) / 2;
				vec meso_3 = (p3 + p2) / 2;

				vec dir1 = p1 - p2;
				vec dir2 = p3 - p2;
				vec dir3 = p3 - p1;

				vec provolh1 = dir2.ProjectTo(dir1);
				vec provolh2 = dir1.ProjectTo(dir3);
				vec kath1 = dir2 - provolh1;
				vec kath2 = dir1 - provolh2;
				kath1.Normalize();
				kath2.Normalize();

				float t1 = (kath2.y*(meso_2.x - meso_1.x) / ((kath1.x*kath2.y) - (kath2.x*kath1.y))) + ((kath2.y*kath2.x) / ((kath1.x*kath2.y) - (kath2.x*kath1.y)))*((meso_1.y - meso_2.y) / (kath2.y));

				vec tomh;
				tomh.x = meso_1.x + kath1.x*t1;
				tomh.y = meso_1.y + kath1.y*t1;
				tomh.z = meso_1.z + kath1.z*t1;

				//	la1 = vvr::LineSeg3D(meso_1.x, meso_1.y, meso_1.z, tomh.x, tomh.y, tomh.z, vvr::Colour::black);
				//	la2 = vvr::LineSeg3D(meso_2.x, meso_2.y, meso_2.z, tomh.x, tomh.y, tomh.z, vvr::Colour::black);
				//	la3 = vvr::LineSeg3D(meso_3.x, meso_3.y, meso_3.z, tomh.x, tomh.y, tomh.z, vvr::Colour::black);

				double aktina = 0.999*(tomh.Distance(p1));
				vvr::Sphere3D sfaira(tomh.x, tomh.y, tomh.z, aktina, vvr::Colour::magenta);
				Sphere sfaira_el(tomh, aktina);
				//gia kathe mia sfaira elenxw ama paraviazetai h sinhikh delaungy dhladh ama periexei mesa ths kapoio allo shmeio
				//opote elenxw gia ola ta shmeia

				for (int g = 0; g < tris.size(); g++){
					vvr::Triangle &t2 = tris[g];
					vec po1 = verts[t2.vi1];
					vec po2 = verts[t2.vi2];
					vec po3 = verts[t2.vi3];

					if (sfaira_el.Contains(po1) || sfaira_el.Contains(po2) || sfaira_el.Contains(po2)){
						violations.push_back(vvr::Sphere3D(tomh.x, tomh.y, tomh.z, aktina, vvr::Colour::magenta));
						sfaires_paraviashs.push_back(sfaira_el);
						trigwna_metavolhs.push_back(geitonika_trigwna[k1]);

						break;
					}

				}
				if (violations.size() == 0){
					printf("H EPANATRIGWNOPOIHSH TELEIWSE\n");
					paraviaseis = false;
					break;
				}
			}
			printf("vrhke %d paraviaseis\n", violations.size());
			printf("ta trigwna metavolhs einai %d \n", trigwna_metavolhs.size());

			///////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////

			//sthn periptwsh pou iparxoun paraviaseis ths sinthikhs delangy pragmatopoiw tis e3eis allages~
			
			if (paraviaseis == true){
				for (int h = 0; h < trigwna_metavolhs.size(); h++){
					bool aaa = false;
					vvr::Triangle &t1 = tris[trigwna_metavolhs[h]];
					for (int g2 = 0; g2 < tris.size(); g2++){
				//		printf("to trigwno%d\n",trigwna_metavolhs[h]);
						bool idio_trigwno = false;
						
						vvr::Triangle &t2 = tris[g2];

						if (trigwna_metavolhs[h] == g2){
							idio_trigwno = true;
						}

						if ((((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.00001) || (fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi1].z) < 0.00001) && ((fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi2].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi3].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi3].z) < 0.0001))) || ((fabs(verts[t1.vi3].x - verts[t2.vi3].x) < 0.0001 && fabs(verts[t1.vi3].y - verts[t2.vi3].y) < 0.0001 && fabs(verts[t1.vi3].z - verts[t2.vi3].z) < 0.0001) && ((fabs(verts[t1.vi1].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi1].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi1].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi1].z - verts[t2.vi2].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi1].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi1].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi1].z) < 0.0001) || (fabs(verts[t1.vi2].x - verts[t2.vi2].x) < 0.0001 && fabs(verts[t1.vi2].y - verts[t2.vi2].y) < 0.0001 && fabs(verts[t1.vi2].z - verts[t2.vi2].z) < 0.0001)))) && (idio_trigwno == false)){
							
							///
							
							bool ep1 = false;
							bool ep2 = false;
							bool ep3 = false;
							bool ep4 = false;
							bool ep5 = false;
							bool ep6 = false;

							//elenxos gia to 1o trigwno

							vec d1 = verts[t1.vi2] - verts[t1.vi1];
							vec d2 = verts[t1.vi3] - verts[t1.vi1];

							vec pro1 = d2.ProjectTo(d1);
							vec no1 = d2 - pro1;
							no1.Normalize();
							Plane p1(verts[t1.vi1], no1);

							if (p1.IsOnPositiveSide(verts[t1.vi1]) && p1.IsOnPositiveSide(verts[t1.vi2]) && p1.IsOnPositiveSide(verts[t1.vi3]) && p1.IsOnPositiveSide(verts[t2.vi1]) && p1.IsOnPositiveSide(verts[t2.vi2]) && p1.IsOnPositiveSide(verts[t2.vi3])){
								ep1 = true;
								printf("ep21\n");
							}

							d1 = verts[t1.vi1] - verts[t1.vi2];
							d2 = verts[t1.vi3] - verts[t1.vi2];

							pro1 = d1.ProjectTo(d2);
							no1 = d1 - pro1;
							no1.Normalize();
							Plane p2(verts[t1.vi2], no1);
							if (p2.IsOnPositiveSide(verts[t1.vi1]) && p2.IsOnPositiveSide(verts[t1.vi2]) && p2.IsOnPositiveSide(verts[t1.vi3]) && p2.IsOnPositiveSide(verts[t2.vi1]) && p2.IsOnPositiveSide(verts[t2.vi2]) && p2.IsOnPositiveSide(verts[t2.vi3])){
								ep2 = true;
								printf("ep22\n");
							}


							d1 = verts[t1.vi1] - verts[t1.vi3];
							d2 = verts[t1.vi2] - verts[t1.vi3];

							pro1 = d2.ProjectTo(d1);
							no1 = d2 - pro1;
							no1.Normalize();
							Plane p3(verts[t1.vi3], no1);
							if (p3.IsOnPositiveSide(verts[t1.vi1]) && p3.IsOnPositiveSide(verts[t1.vi2]) && p3.IsOnPositiveSide(verts[t1.vi3]) && p3.IsOnPositiveSide(verts[t2.vi1]) && p3.IsOnPositiveSide(verts[t2.vi2]) && p3.IsOnPositiveSide(verts[t2.vi3])){
								ep3 = true;
								printf("ep23\n");
							}


							//adistixa gia to deutero trigwno elenxoume thn kirtwthta tou tetrapleurou

							d1 = verts[t2.vi2] - verts[t2.vi1];
							d2 = verts[t2.vi3] - verts[t2.vi1];

							pro1 = d2.ProjectTo(d1);
							no1 = d2 - pro1;
							no1.Normalize();
							Plane p4(verts[t2.vi1], no1);

							if (p4.IsOnPositiveSide(verts[t1.vi1]) && p4.IsOnPositiveSide(verts[t1.vi2]) && p4.IsOnPositiveSide(verts[t1.vi3]) && p4.IsOnPositiveSide(verts[t2.vi1]) && p4.IsOnPositiveSide(verts[t2.vi2]) && p4.IsOnPositiveSide(verts[t2.vi3])){
								ep4 = true;
								printf("ep24\n");
							}


							d1 = verts[t2.vi1] - verts[t2.vi2];
							d2 = verts[t2.vi3] - verts[t2.vi2];

							pro1 = d1.ProjectTo(d2);
							no1 = d1 - pro1;
							no1.Normalize();
							Plane p5(verts[t2.vi2], no1);
							if (p5.IsOnPositiveSide(verts[t1.vi1]) && p5.IsOnPositiveSide(verts[t1.vi2]) && p5.IsOnPositiveSide(verts[t1.vi3]) && p5.IsOnPositiveSide(verts[t2.vi1]) && p5.IsOnPositiveSide(verts[t2.vi2]) && p5.IsOnPositiveSide(verts[t2.vi3])){
								ep5 = true;
								printf("ep25\n");
							}

							d1 = verts[t2.vi1] - verts[t2.vi3];
							d2 = verts[t2.vi2] - verts[t2.vi3];

							pro1 = d2.ProjectTo(d1);
							no1 = d2 - pro1;
							no1.Normalize();
							Plane p6(verts[t2.vi3], no1);
							if (p6.IsOnPositiveSide(verts[t1.vi1]) && p6.IsOnPositiveSide(verts[t1.vi2]) && p6.IsOnPositiveSide(verts[t1.vi3]) && p6.IsOnPositiveSide(verts[t2.vi1]) && p6.IsOnPositiveSide(verts[t2.vi2]) && p6.IsOnPositiveSide(verts[t2.vi3])){
								ep6 = true;
								printf("ep26\n");
							}

							int temp11 = t1.vi1;
							int temp12 = t1.vi2;
							int temp13 = t1.vi3;
							int temp21 = t2.vi1;
							int temp22 = t2.vi2;
							int temp23 =	t2.vi3;
							if ((verts[t1.vi2].Equals(verts[t2.vi1])) || (verts[t1.vi2].Equals(verts[t2.vi2])) || (verts[t1.vi2].Equals(verts[t2.vi3]))){
								if ((verts[t1.vi3].Equals(verts[t2.vi1])) || (verts[t1.vi3].Equals(verts[t2.vi2])) || (verts[t1.vi3].Equals(verts[t2.vi3]))){

									if ((verts[t2.vi1].Equals(verts[t1.vi1])) || (verts[t2.vi1].Equals(verts[t1.vi2])) || (verts[t2.vi1].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi2].Equals(verts[t1.vi1])) || (verts[t2.vi2].Equals(verts[t1.vi2])) || (verts[t2.vi2].Equals(verts[t1.vi3]))){

											if (ep1 == true && ep3 == true && ep5 == true && ep6 == true){

												printf("alagh 21\n");
												printf("trigwno %d\n",trigwna_metavolhs[h]);
												t1.vi1 = temp11;
												t1.vi2 = temp23;
												t1.vi3 = temp12;

												vvr::Triangle t11(&verts, temp11, temp23, temp12);
												
												tris[trigwna_metavolhs[h]] = t11;
												
												
												
												
												t2.vi1 = temp11;
												t2.vi2 = temp23;
												t2.vi3 = temp13;

												vvr::Triangle t12(&verts, temp11, temp23, temp13);


												
												tris[g2] = t12;

								

												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t11.vi1;
												 temp12 = t11.vi2;
												 temp13 = t11.vi3;
												 temp21 = t12.vi1;
												 temp22 = t12.vi2;
												 temp23 = t12.vi3;
												aaa = true;
												break;
											}
										}	
									}
									//
									if ((verts[t2.vi1].Equals(verts[t1.vi1])) || (verts[t2.vi1].Equals(verts[t1.vi2])) || (verts[t2.vi1].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi3].Equals(verts[t1.vi1])) || (verts[t2.vi3].Equals(verts[t1.vi2])) || (verts[t2.vi3].Equals(verts[t1.vi3]))){
											if (ep1 == true && ep3 == true && ep4 == true && ep5 == true){
												printf("alagh 22\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp11;
												t1.vi2 = temp22;
												t1.vi3 = temp12;

												vvr::Triangle t21(&verts, temp11, temp22,temp12);
												tris[trigwna_metavolhs[h]] = t21;
												
												
										

												t2.vi1 = temp11;
												t2.vi2 = temp22;
												t2.vi3 = temp13;
												vvr::Triangle t22(&verts, temp11,temp22, temp13);
												
												tris[g2] = t22;
												
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t21.vi1;
												 temp12 = t21.vi2;
												 temp13 = t21.vi3;
												 temp21 = t22.vi1;
												 temp22 = t22.vi2;
												 temp23 = t22.vi3;
												aaa = true;
												break;
											}
										}
									}
									if ((verts[t2.vi2].Equals(verts[t1.vi1])) || (verts[t2.vi2].Equals(verts[t1.vi2])) || (verts[t2.vi2].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi3].Equals(verts[t1.vi1])) || (verts[t2.vi3].Equals(verts[t1.vi2])) || (verts[t2.vi3].Equals(verts[t1.vi3]))){
											if (ep1 == true && ep3 == true && ep4 == true && ep6 == true){
												printf("alagh 23\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp11;
												t1.vi2 = temp21;
												t1.vi3 = temp12;

												vvr::Triangle t31(&verts, temp11,temp21,temp12);
												tris[trigwna_metavolhs[h]] = t31;
												


////////////////////////////////////////////////////////////////////

								


												t2.vi1 = temp11;
												t2.vi2 = temp21;
												t2.vi3 = temp13;
												vvr::Triangle t32(&verts, temp11,temp21,temp13);
												
												tris[g2] = t32;

												////////////////////////////////////////////////////////////////////

												
												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t31.vi1;
												 temp12 = t31.vi2;
												 temp13 = t31.vi3;
												 temp21 = t32.vi1;
												 temp22 = t32.vi2;
												
												 temp23 = t32.vi3;
												aaa = true;
												break;
											}
										}
									}
								}
							}


							if ((verts[t1.vi1].Equals(verts[t2.vi1])) || (verts[t1.vi1].Equals(verts[t2.vi2])) || (verts[t1.vi1].Equals(verts[t2.vi3]))){
								if ((verts[t1.vi3].Equals(verts[t2.vi1])) || (verts[t1.vi3].Equals(verts[t2.vi2])) || (verts[t1.vi3].Equals(verts[t2.vi3]))){

									if ((verts[t2.vi1].Equals(verts[t1.vi1])) || (verts[t2.vi1].Equals(verts[t1.vi2])) || (verts[t2.vi1].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi2].Equals(verts[t1.vi1])) || (verts[t2.vi2].Equals(verts[t1.vi2])) || (verts[t2.vi2].Equals(verts[t1.vi3]))){
											if (ep1 == true && ep2 == true && ep5 == true && ep6 == true){
												printf("alagh 24\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp12;
												t1.vi2 = temp23;
												t1.vi3 = temp11;


												vvr::Triangle t41(&verts,temp12,temp23,temp11);
											
												tris[trigwna_metavolhs[h]] = t41;
												

												
												////////////////////////////////////////////////////////////////////

												

												t2.vi1 = temp12;
												t2.vi2 = temp23;
												t2.vi3 = temp13;
												vvr::Triangle t42(&verts, temp12,temp23,temp13);

												
												tris[g2] = t42;
										
												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t41.vi1;
												 temp12 = t41.vi2;
												 temp13 = t41.vi3;
												 temp21 = t42.vi1;
												 temp22 = t42.vi2;
												 temp23 = t42.vi3;
												aaa = true;
												break;
											}
										}
									}
									//
									if ((verts[t2.vi1].Equals(verts[t1.vi1])) || (verts[t2.vi1].Equals(verts[t1.vi2])) || (verts[t2.vi1].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi3].Equals(verts[t1.vi1])) || (verts[t2.vi3].Equals(verts[t1.vi2])) || (verts[t2.vi3].Equals(verts[t1.vi3]))){

											if (ep1 == true && ep2 == true && ep5 == true && ep4 == true){
												printf("alagh 25\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp12;
												t1.vi2 = temp22;
												t1.vi3 = temp11;


												vvr::Triangle t51(&verts,temp12,temp22,temp11);
												tris[trigwna_metavolhs[h]] = t51;
												
												////////////////////////////////////////////////////////////////////

												
												t2.vi1 = temp12;
												t2.vi2 = temp22;
												t2.vi3 = temp13;
												vvr::Triangle t52(&verts,temp12,temp22,temp13);

											
												
												tris[g2] = t52;

												
												////////////////////////////////////////////////////////////////////

												
												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t51.vi1;
												 temp12 = t51.vi2;
												temp13 = t51.vi3;
												 temp21 = t52.vi1;
												aaa = true;
												 temp22 = t52.vi2;
												 temp23 = t52.vi3;
												break;
											}
										}
									}
									if ((verts[t2.vi2].Equals(verts[t1.vi1])) || (verts[t2.vi2].Equals(verts[t1.vi2])) || (verts[t2.vi2].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi3].Equals(verts[t1.vi1])) || (verts[t2.vi3].Equals(verts[t1.vi2])) || (verts[t2.vi3].Equals(verts[t1.vi3]))){
											if (ep1 == true && ep2 == true && ep4 == true && ep6 == true){
												aaa = true;
												printf("alagh 26\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp12;
												t1.vi2 = temp21;
												t1.vi3 = temp11;

												vvr::Triangle t61(&verts, temp12, temp21,temp11);
									
												tris[trigwna_metavolhs[h]] = t61;
												
												////////////////////////////////////////////////////////////////////

												


												t2.vi1 = temp12;
												t2.vi2 = temp21;
												t2.vi3 = temp13;
												vvr::Triangle t62(&verts,temp12,temp21,temp13);
												
												tris[g2] = t62;
												
												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t61.vi1;
												 temp12 = t61.vi2;
												 temp13 = t61.vi3;
												 temp21 = t62.vi1;
												 temp22 = t62.vi2;
												 temp23 = t62.vi3;
												
												break;
											}
										}
									}
								}
							}


							//prwto 1,3

							if ((verts[t1.vi1].Equals(verts[t2.vi1])) || (verts[t1.vi1].Equals(verts[t2.vi2])) || (verts[t1.vi1].Equals(verts[t2.vi3]))){
								if ((verts[t1.vi2].Equals(verts[t2.vi1])) || (verts[t1.vi2].Equals(verts[t2.vi2])) || (verts[t1.vi2].Equals(verts[t2.vi3]))){

									if ((verts[t2.vi1].Equals(verts[t1.vi1])) || (verts[t2.vi1].Equals(verts[t1.vi2])) || (verts[t2.vi1].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi2].Equals(verts[t1.vi1])) || (verts[t2.vi2].Equals(verts[t1.vi2])) || (verts[t2.vi2].Equals(verts[t1.vi3]))){
											if (ep3 == true && ep2 == true && ep5 == true && ep6 == true){
												aaa = true;
												printf("allagh 27\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp13;
												t1.vi2 = temp23;
												t1.vi3 = temp11;

												vvr::Triangle t71(&verts, temp13,temp23,temp11);
												tris[trigwna_metavolhs[h]] = t71;
												
												////////////////////////////////////////////////////////////////////

												

												t2.vi1 = temp13;
												t2.vi2 = temp23;
												t2.vi3 = temp12;

												vvr::Triangle t72(&verts, temp13,temp23,temp12);
												
												tris[g2] = t72;
												
												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t71.vi1;
												 temp12 = t71.vi2;
												 temp13 = t71.vi3;
												 temp21 = t72.vi1;
												 temp22 = t72.vi2;
												 temp23 = t72.vi3;
												
												break;
											}
										}
									}
									//
									if ((verts[t2.vi1].Equals(verts[t1.vi1])) || (verts[t2.vi1].Equals(verts[t1.vi2])) || (verts[t2.vi1].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi3].Equals(verts[t1.vi1])) || (verts[t2.vi3].Equals(verts[t1.vi2])) || (verts[t2.vi3].Equals(verts[t1.vi3]))){
											if (ep3 == true && ep2 == true && ep5 == true && ep4 == true){
												aaa = true;
												printf("allagh 28\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp13;
												t1.vi2 = temp22;
												t1.vi3 = temp11;

												vvr::Triangle t81(&verts,temp13,temp22, temp11);
												
												tris[trigwna_metavolhs[h]] = t81;
												

												////////////////////////////////////////////////////////////////////

												
												t2.vi1 = temp13;
												t2.vi2 = temp22;
												t2.vi3 = temp12;

												vvr::Triangle t82(&verts, temp13, temp22, temp12);
												
												
												tris[g2] = t82;


												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												 temp11 = t81.vi1;
												 temp12 = t81.vi2;
												 temp13 = t81.vi3;
												 temp21 = t82.vi1;
												 temp22 = t82.vi2;
												 temp23 = t82.vi3;
												
												break;
											}
										}
									}
									if ((verts[t2.vi2].Equals(verts[t1.vi1])) || (verts[t2.vi2].Equals(verts[t1.vi2])) || (verts[t2.vi2].Equals(verts[t1.vi3]))){
										if ((verts[t2.vi3].Equals(verts[t1.vi1])) || (verts[t2.vi3].Equals(verts[t1.vi2])) || (verts[t2.vi3].Equals(verts[t1.vi3]))){
											if (ep3 == true && ep2 == true && ep4 == true && ep6 == true){
												aaa = true;
												printf("allagh 29\n");
												printf("trigwno %d\n", trigwna_metavolhs[h]);
												t1.vi1 = temp13;
												t1.vi2 = temp21;
												t1.vi3 = temp11;

												vvr::Triangle t91(&verts, temp13, temp21,temp11);
												tris[trigwna_metavolhs[h]] = t91;
												
												/////////////////////////////////////////////////


												t2.vi1 = temp13;
												t2.vi2 = temp21;
												t2.vi3 = temp12;

												vvr::Triangle t92(&verts,temp13,temp21,temp12);
												
											
												tris[g2] = t92;

												
												/////////////////////////////////////////////////
												//ama dior8wsei mai paravias metaferomaste sthn epomenh
												
												 temp11 = t91.vi1;
												 temp12 = t91.vi2;
												 temp13 = t91.vi3;
												 temp21 = t92.vi1;
												 temp22 = t92.vi2;
												 temp23 = t92.vi3;
												
												break;

											}
										}
									}
								}
							}
							/////

						}
						

					}
					if (aaa == true){
							break;
					}
				}
			}
		//	break;
			arithmos_epan++;
		}
	}
}