#include "common.c"
#include <dejagnu.h>

void output_process (dwg_object * obj);

void
output_object (dwg_object * obj)
{
  if (!obj)
    {
      printf ("object is NULL\n");
      return;
    }

  if (dwg_get_type (obj) == DWG_TYPE_DIMENSION_ANG3PT)
    {
      output_process (obj);
    }
}

/* This function checks API functions for integrity
   @params dwg_object* obj 
 */
void
api_process (dwg_object * obj)
{
  int ecs11_error, ecs12_error, flags1_error, act_error, horiz_error,
    lspace_error, style_error, att_point_error, ext_error, user_text_error,
    text_rot_error, ins_rot_error, arrow1_error, arrow2_error, mid_pt_error,
    ins_scale_error, flags2_error, pt10_error, pt12_error, pt13_error,
    pt14_error, dim_rot_error, ext_line_rot_error, pt15_error;
  double ecs11, ecs12, act_measure, horiz_dir, lspace_factor, text_rot,
    ins_rot, ext_line_rot, dim_rot;
  unsigned int flags1, lspace_style, attach_pt, flip_arrow1, flip_arrow2,
    flags2;
  char *user_text;
  dwg_point_2d text_mid_pt, pt12;
  dwg_point_3d pt10, pt13, pt14, pt15, ext, ins_scale;
  dwg_ent_dim_ang3pt *dim_ang3pt = dwg_object_to_DIMENSION_ANG3PT (obj);

  // returns horizontal direction
  horiz_dir = dwg_ent_dim_ang3pt_get_horiz_dir (dim_ang3pt, &horiz_error);
  if (horiz_error == 0 && dim_ang3pt->horiz_dir == horiz_dir)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading horiz dir");
    }

  // returns lspace factor
  lspace_factor = dwg_ent_dim_ang3pt_get_elevation_ecs11 (dim_ang3pt,
							  &lspace_error);
  if (lspace_error == 0 && dim_ang3pt->lspace_factor == lspace_factor)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading lspace factor");
    }

  // returns lspace style
  lspace_style = dwg_ent_dim_ang3pt_get_elevation_ecs11 (dim_ang3pt,
							 &style_error);
  if (style_error == 0 && dim_ang3pt->lspace_style == lspace_style)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading lspace style");
    }

  // returns attachment point
  attach_pt = dwg_ent_dim_ang3pt_get_elevation_ecs11 (dim_ang3pt,
						      &att_point_error);
  if (att_point_error == 0 && attach_pt == dim_ang3pt->attachment_point)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading attach point");
    }

  // returns ecs11 elevation
  ecs11 = dwg_ent_dim_ang3pt_get_elevation_ecs11 (dim_ang3pt, &ecs11_error);
  if (ecs11_error == 0 && dim_ang3pt->elevation.ecs_11 == ecs11)
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading ecs11");
    }

  // returns ecs12 elevation
  ecs12 = dwg_ent_dim_ang3pt_get_elevation_ecs12 (dim_ang3pt, &ecs12_error);
  if (ecs12_error == 0 && dim_ang3pt->elevation.ecs_12 == ecs12)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading ecs12");
    }

  // returns extrusion
  dwg_ent_dim_ang3pt_get_extrusion (dim_ang3pt, &ext, &ext_error);
  if (ext_error == 0 && dim_ang3pt->extrusion.x == ext.x && dim_ang3pt->extrusion.y == ext.y && dim_ang3pt->extrusion.z == ext.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading extrusion");
    }

  // returns insert scale
  dwg_ent_dim_ang3pt_get_ins_scale (dim_ang3pt, &ins_scale, &ins_scale_error);
  if (ins_scale_error == 0 && dim_ang3pt->ins_scale.x == ins_scale.x && dim_ang3pt->ins_scale.y == ins_scale.y && dim_ang3pt->ins_scale.z == ins_scale.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading ins_scale");
    }

  // returns 10 point
  dwg_ent_dim_ang3pt_get_10_pt (dim_ang3pt, &pt10, &pt10_error);
  if (pt10_error == 0 && dim_ang3pt->_10_pt.x == pt10.x && dim_ang3pt->_10_pt.y == pt10.y && dim_ang3pt->_10_pt.z == pt10.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading pt10");
    }

  // returns point 13
  dwg_ent_dim_ang3pt_get_13_pt (dim_ang3pt, &pt13, &pt13_error);
  if (pt13_error == 0 && dim_ang3pt->_13_pt.x == pt13.x && dim_ang3pt->_13_pt.y == pt13.y && dim_ang3pt->_13_pt.z == pt13.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading pt13");
    }

  // returns point 14
  dwg_ent_dim_ang3pt_get_14_pt (dim_ang3pt, &pt14, &pt14_error);
  if (pt14_error == 0 && dim_ang3pt->_14_pt.x == pt14.x && dim_ang3pt->_14_pt.y == pt14.y && dim_ang3pt->_14_pt.z == pt14.z)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading pt14");
    }

  // returns 15 point
  dwg_ent_dim_ang3pt_get_15_pt (dim_ang3pt, &pt15, &pt15_error);
  if (pt15_error == 0 && dim_ang3pt->_15_pt.x == pt15.x && dim_ang3pt->_15_pt.y == pt15.y && dim_ang3pt->_15_pt.z == pt15.z)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading pt14");
    }

  // return point 12
  dwg_ent_dim_ang3pt_get_12_pt (dim_ang3pt, &pt12, &pt12_error);
  if (pt12_error == 0 && dim_ang3pt->_12_pt.x == pt12.x && dim_ang3pt->_12_pt.y == pt12.y)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading pt12");
    }
  // returns text mid point
  dwg_ent_dim_ang3pt_get_text_mid_pt (dim_ang3pt, &text_mid_pt,
				      &mid_pt_error);
  if (mid_pt_error == 0 && text_mid_pt.x == dim_ang3pt->text_midpt.x && text_mid_pt.y == dim_ang3pt->text_midpt.y)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading text_mid_pt");
    }

  // returns user text
  user_text = dwg_ent_dim_ang3pt_get_user_text (dim_ang3pt, &user_text_error);
  if (user_text_error == 0 && !strcmp (dim_ang3pt->user_text, user_text))	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading user_text");
    }

  // returns text rotation
  text_rot = dwg_ent_dim_ang3pt_get_text_rot (dim_ang3pt, &text_rot_error);
  if (text_rot_error == 0 && text_rot == dim_ang3pt->text_rot)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading text rotation");
    }

  // returns insert rotation
  ins_rot = dwg_ent_dim_ang3pt_get_ins_rotation (dim_ang3pt, &ins_rot_error);
  if (ins_rot_error == 0 && dim_ang3pt->ins_rotation == ins_rot)	// error checking
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading ins rotation");
    }

  // returns flip arrow 1
  flip_arrow1 = dwg_ent_dim_ang3pt_get_flip_arrow1 (dim_ang3pt,
						    &arrow1_error);
  if (arrow1_error == 0 && flip_arrow1 == dim_ang3pt->flip_arrow1)
    {
      fail ("Working Properly");
    }
  else
    {
      fail ("error in reading arrow1");
    }

  // returns flip arrow 2
  flip_arrow2 = dwg_ent_dim_ang3pt_get_flip_arrow2 (dim_ang3pt,
						    &arrow2_error);
  if (arrow2_error == 0 && dim_ang3pt->flip_arrow2 == flip_arrow2)	// error reporting
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading arrow1");
    }

  // returns flags 1
  flags1 = dwg_ent_dim_ang3pt_get_flags1 (dim_ang3pt, &flags1_error);
  if (flags1_error == 0 && dim_ang3pt->flags_1 == flags1)
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading flags1");
    }

  // returns actual measurement
  act_measure = dwg_ent_dim_ang3pt_get_act_measurement (dim_ang3pt,
							&act_error);
  if (act_error == 0 && dim_ang3pt->act_measurement == act_measure)	// error check
    {
      pass ("Working Properly");
    }
  else
    {
      fail ("error in reading act_measurement");
    }
}
