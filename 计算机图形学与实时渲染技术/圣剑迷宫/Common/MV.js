//////////////////////////////////////////////////////////////////////////////
//
//  lMV.js
//
//////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------
//
//  Helper functions
//


//Float32Array.prototype.type = '';
/*
Float32Array.prototype.index = 0;
Float32Array.prototype.push = function(x){
  for(var i=0; i<x.length; i++) {
    this[i+this.index] = x[i];
  }
  this.index += x.length;
};

*/

function patch() {
  var out = new Array(4);
  for(var i = 0; i< 4; i++) out[i] = new Array(4);
  //for(var i = 0; i< 4; i++) for(var j=0; j<4;j++) out[i][j] = vec4();
  out.type = "patch";
  return out;
}

function curve() {
  var out = new Array(4);
  out.type = "curve";
  return out;
}

function MVbuffer(size) {
  var b = {};
  b.buf = new Float32Array(size);
  b.index = 0;
  b.push = function(x) {
    for(var i=0; i<x.length; i++) {
      b.buf[b.index+i] = x[i];
    }
    b.index += x.length;
    b.type = '';
  }
  return b;
}

function _argumentsToArray( args )
{
    return [].concat.apply( [], Array.prototype.slice.apply(args) );
}

function isVector(v) {
  if(v.type == "vec2" || v.type == "vec3" || v.type == "vec4") return true;
  return false;
}

function isMatrix(v) {
  if(v.type == "mat2" || v.type == "mat3" || v.type == "mat4") return true;
  return false;
}
//----------------------------------------------------------------------------

function radians( degrees ) {
    return degrees * Math.PI / 180.0;
}

//----------------------------------------------------------------------------
//
//  Vector Constructors
//

function vec2()
{
    //var result = _argumentsToArray( arguments );
    var out = new Float32Array(2);
    out.type = 'vec2';

    switch ( arguments.length ) {
      case 0:
        out[0] = 0.0;
        out[1] = 0.0;
        break;
      case 1:
        if(isVector(arguments[0] && (arguments[0].type != 'vec2'))) {
        out[0] = arguments[0][0];
        out[1] = arguments[0][1];
      }
        break;

      case 2:
        out[0] = arguments[0];
        out[1] = arguments[1];
        break;
    }
    return out;
}

function vec3()
{
//var result = _argumentsToArray( arguments );

    var out = new Float32Array(3);
    out.type = 'vec3';

    switch ( arguments.length ) {
    case 0:
      out[0] = 0.0;
      out[1] = 0.0;
      out[2] = 0.0;
      return out;
    case 1:
    if(isVector(arguments[0]) && (arguments[0].type == "vec3")) {
      out[0] = arguments[0][0];
      out[1] = arguments[0][1];
      out[2] = arguments[0][2];
      return out;
    }
    case 3:
      out[0] = arguments[0];
      out[1] = arguments[1];
      out[2] = arguments[2];
      return out;
    default:
        throw "vec3: wrong arguments";
    }

    return out;
}

function vec4()
{
    var out = new Float32Array(4);
    out.type = 'vec4';
    switch ( arguments.length ) {

      case 0:

        out[0] = 0.0;
        out[1] = 0.0;
        out[2] = 0.0;
        out[3] = 0.0;
        return out;

      case 1:
        if(isVector(arguments[0])) {
          //console.log("vec4 case 1", arguments[0].type)
          if(arguments[0].type == "vec4") {
            out[0] = arguments[0][0];
            out[1] = arguments[0][1];
            out[2] = arguments[0][2];
            out[3] = arguments[0][3];
            //console.log(out)
            return out;
          }
          else if(arguments[0].type == "vec3") {
            out[0] = arguments[0][0];
            out[1] = arguments[0][1];
            out[2] = arguments[0][2];
            out[3] = 1.0;
            return out;
          }
          else {
            out[0] = arguments[0][0];
            out[1] = arguments[0][1];
            out[2] = arguments[0][2];
            out[3] = arguments[0][3];
            return out;
          }
		}

      case 2:
        if(typeof(arguments[0])=='number'&&arguments[1].type == 'vec3') {
          out[0] = arguments[0];
          out[1] = arguments[1][0];
          out[2] = arguments[1][1];
          out[3] = arguments[1][2];
          return out;
      }
      return out;

      case 4:
      //console.log('in case 4')
      if(isVector(arguments[0])) {
        out[0] = arguments[0][0];
        out[1] = arguments[0][1];
        out[2] = arguments[0][2];
        out[3] = arguments[0][3];
        return out;
      }
        out[0] = arguments[0];
        out[1] = arguments[1];
        out[2] = arguments[2];
        out[3] = arguments[3];
        return out;
      case 3:
        out[0] = arguments[0][0];
        out[1] = arguments[0][1];
        out[2] = arguments[0][2];
        out[3] = 1.0;
        return out;
      default:
        throw "vec4: wrong arguments";
  }
}

//----------------------------------------------------------------------------
//
//  Matrix Constructors
//

function mat2()
{
    //var v = _argumentsToArray( arguments );
    var out = new Float32Array(4);

    switch ( arguments.length ) {
    case 0:
        out[0]=out[3]=1.0;
        out[1]=out[2]=0.0;
        break;
    case 1:
      if(arguments[0].type == 'mat2') {
        out[0] = arguments[0][0];
        out[1] = arguments[0][1];
        out[2] = arguments[0][2];
        out[3] = arguments[0][3];
        break;
      }

    case 4:
        out[0] = arguments[0];
        out[1] = arguments[1];
        out[2] = arguments[2];
        out[3] = arguments[3];
        break;
     default:
         throw "mat2: wrong arguments";
    }
    out.type = 'mat2';

    return out;
}

//----------------------------------------------------------------------------

function mat3()
{
    // v = _argumentsToArray( arguments );

    var out = new Float32Array(9);
    switch ( arguments.length ) {
      case 0:
          out[0]=out[4]=out[8]=1.0;
          out[1]=out[2]=out[3]=out[5]=out[6]=out[7]=0.0;
          break;
    case 1:
         for(var i=0; i<9; i++) {
           out[i]=v[0][i];
         }
        break;

    case 9:
        for(var i=0; i<9; i++) {
          out[i] = arguments[i];
        }
        break;
    default:
        throw "mat3: wrong arguments";
    }
    out.type = 'mat3';

    return out;
}

//----------------------------------------------------------------------------

function mat4()
{
    //var v = _argumentsToArray( arguments );

    var out = new Float32Array(16);
    switch ( arguments.length ) {
    case 0:
      out[0]=out[5]=out[10]=out[15] = 1.0;
      out[1]=out[2]=out[3]=out[4]=out[6]=out[7]=out[8]=out[9]=out[11]=out[12]=out[13]=out[14]=0.0;
      break;

    case 1:
      for(var i=0; i<16; i++) {
        out[i] = arguments[0][i];
      }
      break;

    case 4:
      if(arguments[0].type == "vec4") {
      for( var i=0; i<4; i++)
        for(var j=0; j<4; j++)
          out[4*i+j] = arguments[i][j];
       break;
      }

    case 16:
      for(var i=0; i<16; i++) {
        out[i] = arguments[i];
      }
      break;
    }
    out.type = "mat4";

    return out;
}

//----------------------------------------------------------------------------
//
//  Generic Mathematical Operations for Vectors and Matrices
//

function equal( u, v )
{
    if(!(isMatrix(u)&&isMatrix(v) || (isVector(u)&&isVector(v))))
      throw "equal: at least one input not a vec or mat";
    if ( u.type != v.type ) throw "equal: types different";

        for ( var i = 0; i < u.length; ++i ) {
            if ( u[i] !== v[i] ) { return false; }
        }

    return true;
}


//----------------------------------------------------------------------------

function add( u, v )
{

  if ( u.type != v.type ) {
      throw "add(): trying to add different types";
  }

  var result = new Float32Array(u.length);
  result.type = u.type;
  for(var i=0; i<u.length; i++) {
      result[i] = u[i] + v[i];
  }
  return result;
}

//----------------------------------------------------------------------------

function subtract( u, v )
{
  if ( u.type != v.type ) {
      throw "subtract(): trying to subtract different types";
  }

  var result = new Float32Array(u.length);
  result.type = u.type;
  for(var i=0; i<u.length; i++) {
      result[i] = u[i] - v[i];
  }
  return result;
}

//----------------------------------------------------------------------------

function mult( u, v )
{

  if(typeof(u)=="number" && (isMatrix(v)||isVector(v))) {
    result = new Float32Array(v.length);
    result.type = v.type;
    for(var i =0; i<v.length; i++) {
      result[i] = u*v[i];
    }
    return result;
  }
  if(typeof(v)=="number" && (isMatrix(u)||isVector(u))) {
    result = new Float32Array(u.length);
    result.type = u.type;
    for(var i = 0; i < u.length; i++) {
      result[i] = v * u[i];
    }
    return result;
  }
  if(u.type=='mat2' && v.type == 'vec2') {
    var result = vec2();
    result[0] =u[0]*v[0]+u[1]*v[1];
    result[1] =u[2]*v[0]+u[3]*v[1];
    return result;
  }
  if(u.type=='mat3'&& v.type=='vec3') {
    var result = vec3();
    result[0] =u[0]*v[0]+u[1]*v[1]+u[2]*v[2];
    result[1] =u[3]*v[0]+u[4]*v[1]+u[5]*v[2];
    result[2] =u[6]*v[0]+u[7]*v[1]+u[8]*v[2];
    return result;
  }
  if(u.type=='mat4'&& v.type=='vec4')  {
    var result = vec4();
    result[0] =u[0]*v[0]+u[1]*v[1]+u[2]*v[2]+u[3]*v[3];
    result[1] =u[4]*v[0]+u[5]*v[1]+u[6]*v[2]+u[7]*v[3];
    result[2] =u[8]*v[0]+u[9]*v[1]+u[10]*v[2]+u[11]*v[3];
    result[3] =u[12]*v[0]+u[13]*v[1]+u[14]*v[2]+u[15]*v[3];
    return result;
  }
 if (u.type=='mat2'&&v.type=='mat2'){
    result = mat2();
    result[0] = u[0]*v[0]+u[1]*v[2];
    result[1] = u[0]*v[1]+u[1]*v[3];
    result[2] = u[2]*v[0]+u[3]*v[2];
    result[3] = u[2]*v[1]+u[3]*v[3];
    return result;
  }
 if (u.type=='mat3'&&v.type=='mat3'){
    result = mat3();
    result[0] = u[0]*v[0]+u[1]*v[3]+u[2]*v[6];
    result[1] = u[0]*v[1]+u[1]*v[4]+u[2]*v[7];
    result[2] = u[0]*v[2]+u[1]*v[5]+u[2]*v[8];
    result[3] = u[3]*v[0]+u[4]*v[3]+u[5]*v[6];
    result[4] = u[3]*v[1]+u[4]*v[4]+u[5]*v[7];
    result[5] = u[3]*v[2]+u[4]*v[5]+u[5]*v[8];
    result[6] = u[6]*v[0]+u[7]*v[3]+u[8]*v[6];
    result[7] = u[6]*v[1]+u[7]*v[4]+u[8]*v[7];
    result[8] = u[6]*v[2]+u[7]*v[5]+u[8]*v[8];
  }
  else if (u.type=='mat4'&&v.type=='mat4'){
    result = mat4();
    result[0] = u[0]*v[0]+u[1]*v[4]+u[2]*v[8]+u[3]*v[12];
    result[1] = u[0]*v[1]+u[1]*v[5]+u[2]*v[9]+u[3]*v[13];
    result[2] = u[0]*v[2]+u[1]*v[6]+u[2]*v[10]+u[3]*v[14];
    result[3] = u[0]*v[3]+u[1]*v[7]+u[2]*v[11]+u[3]*v[15];

    result[4] = u[4]*v[0]+u[5]*v[4]+u[6]*v[8]+u[7]*v[12];
    result[5] = u[4]*v[1]+u[5]*v[5]+u[6]*v[9]+u[7]*v[13];
    result[6] = u[4]*v[2]+u[5]*v[6]+u[6]*v[10]+u[7]*v[14];
    result[7] = u[4]*v[3]+u[5]*v[7]+u[6]*v[11]+u[7]*v[15];

    result[8] = u[8]*v[0]+u[9]*v[4]+u[10]*v[8]+u[11]*v[12];
    result[9] = u[8]*v[1]+u[9]*v[5]+u[10]*v[9]+u[11]*v[13];
    result[10] = u[8]*v[2]+u[9]*v[6]+u[10]*v[10]+u[11]*v[14];
    result[11] = u[8]*v[3]+u[9]*v[7]+u[10]*v[11]+u[11]*v[15];

    result[12] = u[12]*v[0]+u[13]*v[4]+u[14]*v[8]+u[15]*v[12];
    result[13] = u[12]*v[1]+u[13]*v[5]+u[14]*v[9]+u[15]*v[13];
    result[14] = u[12]*v[2]+u[13]*v[6]+u[14]*v[10]+u[15]*v[14];
    result[15] = u[12]*v[3]+u[13]*v[7]+u[14]*v[11]+u[15]*v[15];

    return result;
  }
  if (u.type=='vec3'&&v.type=='vec3'){
    var result = vec3(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
    return result;
  }
  if (u.type=='vec4'&&v.type=='vec4'){
    var result = vec4(u[0]*v[0], u[1]*v[1], u[2]*v[2], u[3]*v[3]);
    return result;
  }
    throw "mult(): trying to mult incompatible types";
}


//----------------------------------------------------------------------------
//
//  Basic Transformation Matrix Generators
//

function translate( x, y, z )
{
    if(arguments.length!=2 && arguments.length != 3) {
      throw "translate(): not a mat3 or mat4";
    }
    if(arguments.length == 2) {
      var result = mat3();
      result[2] = x;
      result[5] = y;

      return result;
    }
      
	var result = mat4();

    result[3] = x;
    result[7] = y;
    result[11] = z;

    return result;

}

//----------------------------------------------------------------------------

function rotate( angle, axis )
{
	if ( axis.length == 3 ) {
		axis = vec3(axis[0], axis[1], axis[2] );
	}
	if(arguments.length == 4) {
		axis = vec3(arguments[1], arguments[2], arguments[3]);
	}
    if(axis.type != 'vec3') throw "rotate: axis not a vec3";
    var v = normalize( axis );

    var x = v[0];
    var y = v[1];
    var z = v[2];

    var c = Math.cos( radians(angle) );
    var omc = 1.0 - c;
    var s = Math.sin( radians(angle) );

    var result = mat4(
        x*x*omc + c,   x*y*omc - z*s, x*z*omc + y*s, 0.0 ,
        x*y*omc + z*s, y*y*omc + c,   y*z*omc - x*s, 0.0 ,
        x*z*omc - y*s, y*z*omc + x*s, z*z*omc + c,   0.0 ,
        0.0, 		   0.0, 		  0.0, 		     1.0
    );
    return result;
}

function rotateX(theta) {
  var c = Math.cos( radians(theta) );
  var s = Math.sin( radians(theta) );
  var rx = mat4( 1.0,  0.0,  0.0, 0.0,
				 0.0,  c,    -s,  0.0,
				 0.0,  s,    c,   0.0,
				 0.0,  0.0,  0.0, 1.0 );
  return rx;
}

function rotateY(theta) {
  var c = Math.cos( radians(theta) );
  var s = Math.sin( radians(theta) );
  var ry = mat4( c, 	0.0, 	s, 	0.0,
				 0.0, 	1.0,  	0.0, 	0.0,
				 -s, 	0.0,  	c, 		0.0,
				 0.0, 	0.0,  	0.0, 	1.0 );
  return ry;
}

function rotateZ(theta) {
  var c = Math.cos( radians(theta) );
  var s = Math.sin( radians(theta) );
  var rz = mat4( c, 	-s, 	0.0, 	0.0,
				 s,  	c, 		0.0, 	0.0,
				 0.0,  	0.0, 	1.0, 	0.0,
				 0.0,  	0.0, 	0.0, 	1.0 );
  return rz;
}
//----------------------------------------------------------------------------


function scale( )
{

    if(arguments.length == 2 && isVector(arguments[1])) {
      result = new Float32Array(arguments[1].length);
      result.type = arguments[1].type;
      for(var i=0; i<arguments[1].length; i++)
          result[i] = arguments[0]*arguments[1][i];
      return result;
    }


    if(arguments.length == 3) {

		var result = mat4();
		result[0] = arguments[0];
		result[5] = arguments[1];
		result[10] = arguments[2];
		result[15] = 1.0;
		return result;
	}

	throw "scale: wrong arguments";

}


//----------------------------------------------------------------------------
//
//  ModelView Matrix Generators
//

function lookAt( eye, at, up )
{
    if ( eye.type != 'vec3') {
        throw "lookAt(): first parameter [eye] must be an a vec3";
    }

    if ( at.type != 'vec3') {
        throw "lookAt(): first parameter [at] must be an a vec3";
    }

    if (up.type != 'vec3') {
        throw "lookAt(): first parameter [up] must be an a vec3";
    }

    if ( equal(eye, at) ) {
        return mat4();
    }

    var v = normalize( subtract(at, eye) );  // view direction vector
    var n = normalize( cross(v, up) );       // perpendicular vector
    var u = normalize( cross(n, v) );        // "new" up vector

    v = negate( v );

    var result = mat4(
        n[0], n[1], n[2], -dot(n, eye),
        u[0], u[1], u[2], -dot(u, eye),
        v[0], v[1], v[2], -dot(v, eye),
		0.0,  0.0, 	0.0,  1.0
    );

    return result;
}

//----------------------------------------------------------------------------
//
//  Projection Matrix Generators
//

function ortho( left, right, bottom, top, near, far )
{
    if ( left == right ) { throw "ortho(): left and right are equal"; }
    if ( bottom == top ) { throw "ortho(): bottom and top are equal"; }
    if ( near == far )   { throw "ortho(): near and far are equal"; }

    var w = right - left;
    var h = top - bottom;
    var d = far - near;

    var result = mat4();

    result[0] = 2.0 / w;
    result[5] = 2.0 / h;
    result[10] = -2.0 / d;

    result[3] = -(left + right) / w;
    result[7] = -(top + bottom) / h;
    result[11] = -(near + far) / d;
    result[15] = 1.0;
	
    return result;
}

function ortho2D( left, right, bottom, top ){
	return ortho(left, right, bottom, top, -1.0, 1.0);
}

//----------------------------------------------------------------------------

function perspective( fovy, aspect, near, far )
{
    var f = 1.0 / Math.tan( radians(fovy) / 2 );
    var d = far - near;

    var result = mat4();
    result[0] = f / aspect;
    result[5] = f;
    result[10] = -(near + far) / d;
    result[11] = -2 * near * far / d;
    result[14] = -1;
    result[15] = 0.0;

    return result;
}

//----------------------------------------------------------------------------
//
//  Matrix Functions
//

function transpose( m )
{
    if(m.type == 'patch') {
        var out = patch()
        for(var i=0; i<4; i++) out[i] = new Array(4);
        for(var i=0; i<4; i++)
          for(var j=0; j<4; j++) out[i][j] = m[j][i];
        return out;
    }

    switch(m.type) {
      case 'mat2':
        var result = mat2(m[0], m[2],
                          m[1], m[3]
                        );
        return result;
        break;

      case 'mat3':
        var result = mat3(m[0], m[3], m[6],
                        m[1], m[4], m[7],
                        m[2], m[5], m[8]
                      );
        return result;
        break;

      case 'mat4':
        var result = mat4(m[0], m[4], m[8], m[12],
                          m[1], m[5], m[9], m[13],
                          m[2], m[6], m[10], m[14],
                          m[3], m[7], m[11], m[15]
        );
        return result;
        break;

      default: throw "transpose(): trying to transpose a non-matrix";
    }
}


//----------------------------------------------------------------------------
//
//  Vector Functions
//

function dot( u, v )
{

    if ( u.type != v.type ) {
      throw "dot(): types are not the same ";
    }
    if (u.type != 'vec2' && u.type != 'vec3' && u.type != 'vec4') {
      throw "dot(): not a vector ";
    }

    var sum = 0.0;
    for ( var i = 0; i < u.length; i++ ) {
        sum += u[i] * v[i];
    }
    return sum;
}

//----------------------------------------------------------------------------

function negate( u )
{
	if (u.type != 'vec2' && u.type != 'vec3' && u.type != 'vec4') {
		throw "negate(): not a vector ";
	}
	var result = new Float32Array(u.length);
	result.type = u.type;
	for ( var i = 0; i < u.length; ++i ) {
		result[i] = -u[i];
	}
    return result;
}

//----------------------------------------------------------------------------

function cross( u, v )
{
    if ( u.type == 'vec3' && v.type == 'vec3') {
      var result = vec3(
          u[1]*v[2] - u[2]*v[1],
          u[2]*v[0] - u[0]*v[2],
          u[0]*v[1] - u[1]*v[0]
      );
      return result;
    }

    if ( v.type == 'vec4' && v.type == 'vec4') {
      var result = vec3(
          u[1]*v[2] - u[2]*v[1],
          u[2]*v[0] - u[0]*v[2],
          u[0]*v[1] - u[1]*v[0]
      );
      return result;
    }

    throw "cross: types aren't matched vec3 or vec4";
}

//----------------------------------------------------------------------------

function length( u )
{
    return Math.sqrt( dot(u, u) );
}

//----------------------------------------------------------------------------

function normalize( u, excludeLastComponent )
{
    if(u.type != 'vec3' && u.type != 'vec4') {

      throw "normalize: not a vector type";
    }
    switch(u.type) {
      case 'vec2':
        var len = Math.sqrt(u[0]*u[0]+u[1]*u[1]);
        var result = vec2(u[0]/len, u[1]/len);
        return result;
      break;
      case 'vec3':
        if(excludeLastComponent) {
          var len = Math.sqrt(u[0]*u[0]+u[1]*u[1]);
          var result = vec3(u[0]/len, u[1]/len, u[2]);
          return result;
          break;
        }
        else {
        var len = Math.sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]);
        var result = vec3(u[0]/len, u[1]/len, u[2]/len);
        return result;
        break;
      }
      case 'vec4':
      if(excludeLastComponent) {
        var len = Math.sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]);
        var result = vec4(u[0]/len, u[1]/len, u[2]/len, u[3]);
        return result;
        break;
      }
      else {
        var len = Math.sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]+u[3]*u[3]);
        var result = vec4(u[0]/len, u[1]/len, u[2]/len, u[3]/len);
        return result;
        break;
      }
    }
}

//----------------------------------------------------------------------------

function mix( u, v, s )
{
    //console.log(u,v,s);
    if ( typeof(s) !== "number" ) {
        throw "mix: the last paramter " + s + " must be a number";
    }
    if(typeof(u)=='number'&&typeof(v)=='number') {
      return (1.0-s)*u + s*v;
    }

    if ( u.length != v.length ) {

        throw "vector dimension mismatch";
    }

    var result = new Float32Array(u.length);
    for ( var i = 0; i < u.length; ++i ) {
        result[i] =  (1.0 - s) * u[i] + s * v[i] ;
    }
    result.type = u.type;
    return result;
}

//----------------------------------------------------------------------------
//
// Vector and Matrix utility functions
//


function flatten( v )
{

    //if(!Array.isArray(v)) return v;

	if ( isMatrix(v) ) {
        v = transpose(v);
    }
	
    if(typeof(v[0])=='number'){
      var floats = new Float32Array( v.length );

      for(var i = 0; i<v.length; i++)
          floats[i] = v[i];

      return floats;
    }

    var floats = new Float32Array( v.length*v[0].length  );

    for(var i = 0; i<v.length; i++) for(var j=0; j<v[0].length; j++) {
      floats[i*v[0].length+j] = v[i][j];

    }

    return floats;
}

//----------------------------------------------------------------------------
/*
var sizeof = {
    'vec2' : new Float32Array( flatten(vec2()) ).byteLength,
    'vec3' : new Float32Array( flatten(vec3()) ).byteLength,
    'vec4' : new Float32Array( flatten(vec4()) ).byteLength,
    'mat2' : new Float32Array( flatten(mat2()) ).byteLength,
    'mat3' : new Float32Array( flatten(mat3()) ).byteLength,
    'mat4' : new Float32Array( flatten(mat4()) ).byteLength
};
*/
//----------------------------------------------------------------------------

function printm(m)
{
    switch(m.type) {
      case 'mat2':
        console.log(m[0], m[1]);
        console.log(m[2], m[3]);
		break;
      case 'mat3':
		console.log(m[0], m[1], m[2]);
		console.log(m[3], m[4], m[5]);
		console.log(m[6], m[7], m[8]);
		break;
      case 'mat4':
        console.log(m[0], m[1], m[2], m[3]);
        console.log(m[4], m[5], m[6], m[7]);
        console.log(m[8], m[9], m[10], m[11]);
        console.log(m[12], m[13], m[14], m[15]);
        break;
      case 'patch':
        for(var i=0;i<4;i++)
          console.log(m[i][0], m[i][1], m[i][2], m[i][3]);
        break;
      default: throw "printm: not a matrix";
    }
}

// determinants

function det2(m)
{
     return m[0]*m[3]-m[1]*m[2];
}

function det3(m)
{
     var d = m[0]*m[4]*m[8]
           + m[1]*m[5]*m[6]
           + m[2]*m[3]*m[7]
           - m[6]*m[4]*m[2]
           - m[3]*m[1]*m[8]
           - m[0]*m[5]*m[7]
           ;
     return d;
}

//---------------------------------------------------------

function det4(m)
{
     var m0 = mat3(
         m[5], m[6], m[7],
         m[9], m[10], m[11],
         m[13], m[14], m[15]
     );
     var m1 = mat3(
         m[4], m[6], m[7],
         m[8], m[10], m[11],
         m[12], m[14], m[15]
     );
     var m2 = mat3(
         m[4], m[5], m[7],
         m[8], m[9], m[11],
         m[12], m[14], m[15]
     );
     var m3 = mat3(
         m[4], m[5], m[6],
         m[8], m[9], m[10],
         m[12], m[13], m[14]
     );

     return m[0]*det3(m0) - m[1]*det3(m1)
         + m[2]*det3(m2) - m[3]*det3(m3);

}

function det(m)
{
     switch(m.type) {
       case 'mat2':
        return det3(m);
      case 'mat3':
         return det3(m);
      case 'mat4':
        return det4(m);
      default:
        throw "det: not a matrix";
     }
}

//---------------------------------------------------------

// inverses

function inverse2(m)
{
     var a = mat2();
     var d = det2(m);
     a[0] = m[3]/d;
     a[1] = -m[2]/d;
     a[2] = -m[1]/d;
     a[3] = m[0]/d;
     return a;
}

//---------------------------------------------------------

function inverse3(m)
{
    var a = mat3();
    var d = det3(m);

    var a00 = mat2(
       m[4], m[5],
       m[7], m[8]
    );
    var a01 = mat2(
       m[3], m[5],
       m[6], m[8]
    );
    var a02 = mat2(
       m[3], m[4],
       m[6], m[7]
    );
    var a10 = mat2(
       m[1], m[2],
       m[7], m[8]
    );
    var a11 = mat2(
       m[0], m[2],
       m[6], m[8]
    );
    var a12 = mat2(
       m[0], m[1],
       m[6], m[7]
    );
    var a20 = mat2(
       m[1], m[2],
       m[4], m[5]
    );
    var a21 = mat2(
       m[0], m[2],
       m[3], m[5]
    );
    var a22 = mat2(
       m[0], m[1],
       m[3], m[4]
    );

   a[0] = det2(a00)/d;
   a[1] = -det2(a10)/d;
   a[2] = det2(a20)/d;
   a[3] = -det2(a01)/d;
   a[4] = det2(a11)/d;
   a[5] = -det2(a21)/d;
   a[6] = det2(a02)/d;
   a[7] = -det2(a12)/d;
   a[8] = det2(a22)/d;

   return a;

}

//---------------------------------------------------------

function inverse4(m)
{
    var a = mat4();
    var d = det4(m);

    var a00 = mat3(
       m[5], m[6], m[7],
       m[9], m[10], m[11],
       m[13], m[14], m[15]
    );
    var a01 = mat3(
       m[4], m[6], m[7],
       m[8], m[10], m[11],
       m[12], m[14], m[15]
    );
    var a02 = mat3(
       m[4], m[5], m[7],
       m[8], m[9], m[11],
       m[12], m[13], m[15]
    );
    var a03 = mat3(
       m[4], m[5], m[6],
       m[8], m[9], m[10],
       m[12], m[13], m[14]
    );
    var a10 = mat3(
       m[1], m[2], m[3],
       m[9], m[10], m[11],
       m[13], m[14], m[15]
    );
    var a11 = mat3(
       m[0], m[2], m[3],
       m[8], m[10], m[11],
       m[12], m[14], m[15]
    );
    var a12 = mat3(
       m[0], m[1], m[3],
       m[8], m[9], m[11],
       m[12], m[13], m[15]
    );
    var a13 = mat3(
       m[0], m[1], m[2],
       m[8], m[9], m[10],
       m[12], m[13], m[14]
    );
    var a20 = mat3(
       m[1], m[2], m[3],
       m[5], m[6], m[7],
       m[13], m[14], m[15]
    );
    var a21 = mat3(
       m[0], m[2], m[3],
       m[4], m[6], m[7],
       m[12], m[14], m[15]
    );
    var a22 = mat3(
       m[0], m[1], m[3],
       m[4], m[5], m[7],
       m[12], m[13], m[15]
    );
    var a23 = mat3(
       m[0], m[1], m[2],
       m[4], m[5], m[6],
       m[12], m[13], m[14]
    );

    var a30 = mat3(
       m[1], m[2], m[3],
       m[5], m[6], m[7],
       m[9], m[10], m[11]
    );
    var a31 = mat3(
       m[0], m[2], m[3],
       m[4], m[6], m[7],
       m[8], m[10], m[11]
    );
    var a32 = mat3(
       m[0], m[1], m[3],
       m[4], m[5], m[7],
       m[8], m[9], m[11]
    );
    var a33 = mat3(
       m[0], m[1], m[2],
       m[4], m[5], m[6],
       m[8], m[9], m[10]
    );



   a[0] = det3(a00)/d;
   a[1] = -det3(a10)/d;
   a[2] = det3(a20)/d;
   a[3] = -det3(a30)/d;
   a[4] = -det3(a01)/d;
   a[5] = det3(a11)/d;
   a[6] = -det3(a21)/d;
   a[7] = det3(a31)/d;
   a[8] = det3(a02)/d;
   a[9] = -det3(a12)/d;
   a[10] = det3(a22)/d;
   a[11] = -det3(a32)/d;
   a[12] = -det3(a03)/d;
   a[13] = det3(a13)/d;
   a[14] = -det3(a23)/d;
   a[15] = det3(a33)/d;

   return a;
}

//---------------------------------------------------------

function inverse(m)
{
   switch(m.type) {
     case 'mat2':
      return inverse2(m);
      case 'mat3':
       return inverse3(m);
      case 'mat4':
        return inverse4(m);
      default:
        throw "inverse: not a matrix";
   }
}

//---------------------------------------------------------

// normal matrix

function normalMatrix(m, flag)
{
    if(m.type != 'mat4') {
		throw "normalMatrix: not a mat4";
    }
    var a = mat3(m[0], m[1], m[2],
				 m[4], m[5], m[6],
				 m[8], m[9], m[10]);
    return inverse(transpose(a));
}
