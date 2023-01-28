// ObjModel.js

// 请求加载模型文件
function loadOBJ(fileName){
	var objModel = new OBJModel(fileName);
	var request = new XMLHttpRequest();

	request.onreadystatechange = function() {
		if (request.readyState === 4 && request.status !== 404) {
			console.log(fileName + "加载完毕");
			onReadOBJFile(request.responseText, objModel);
		}
		else if(request.status === 404) // 文件找不到
			console.log("obj文件加载失败：" + fileName);
	}
	// 创建获取文件的请求，最后一个参数表示采用异步方式
	request.open('GET', fileName, true); 
	request.send();  // 发送请求  
	console.log("开始加载材质文件：" + fileName);
	return objModel;
}

function onReadOBJFile(fileString, objModel){
	return objModel.readOBJFile(fileString);
}

// OBJModel对象
// 构造函数(参数为Obj模型文件路径)
var OBJModel = function(fileName) {
	this.fileName = fileName;
	this.mtllib = null;      		 // 材质库，初始化为空
	this.groups = new Array(0);    	 // group数组，初始为空
	this.vertices = new Array(0);	 // 顶点坐标数组，初始为空
	this.normals = new Array(0);	 // 顶点法向数组，初始为空
	this.texcoords = new Array(0); 	 // 顶点纹理坐标数组，初始为空
	this.complete = false;		 	 // obj文件是否读取完毕
	this.ready = false;				 // 为true则一切就绪，可直接绘制了
}

// 读取obj文件内容
OBJModel.prototype.readOBJFile = function(fileString){
	console.log("开始读取OBJ文件" + this.fileName + "内容");
	// 用换行符对文件进行切分，即获取每一行内容，存为数组
	var lines = fileString.split('\n');  
	lines.push(null); // 添加一个null数组元素，作为结束标志
	var index = 0;    // lines数组下标

	var currentGroup = null; // 当前group
  
	// 逐行进行解析
	var line;  // 存储待解析的一行字符
	var sp = new StringParser();  // 创建字符串解析器
	var x, y, z, s, t;	// 临时变量
	while ((line = lines[index++]) != null) {
		sp.init(line);    			// 初始化StringParser
		var command = sp.getWord(); // 获取当前行的指令
		if(command == null)	 continue;  // 当前行为空行

		switch(command){
		case '#':
			continue;  // 跳过注释行
		case 'mtllib': // 读取材质文件
			var path = this.parseMtllib(sp, this.fileName);
			this.mtllib = new MTLLib(path);  // 创建MTLLib对象
			loadMTL(this.mtllib);	 // 加载材质文件到this.mtllib
			continue; // 继续处理下一行
		case 'v':   // 读取顶点
			x = sp.getFloat();
			y = sp.getFloat();
			z = sp.getFloat();
			this.vertices.push(vec3(x, y, z)); 
			continue; // 继续处理下一行
		case 'vn':   // 读取法向
			x = sp.getFloat();
			y = sp.getFloat();
			z = sp.getFloat();
			this.normals.push(vec3(x, y, z)); 
			continue; // 继续处理下一行
		case 'vt':   // 读取纹理坐标
			s = sp.getFloat();
			t = sp.getFloat();
			this.texcoords.push(vec2(s, t)); 
			continue; // 继续处理下一行
		case 'o':
		case 'g':   // 组对象名称行
			// 如果前一组对象没有顶点，则将其从group数组中弹出
			if(currentGroup != null && currentGroup.vertices.length == 0)
				this.groups.pop();
			// 读取组对象名称并创建组对象
			currentGroup = new Group(sp.getWord());
			this.groups.push(currentGroup);
			continue; // 继续处理下一行
		case 'usemtl': // 读取当前组对象所使用的材质名称
			// 如果当前Group已有材质，则新建一个Group对象
			// 该Group对象名称和当前Group一样
			if(currentGroup.mtlName != null){
				currentGroup = new Group(currentGroup.name);
				this.groups.push(currentGroup);
			}
			currentGroup.mtlName = sp.getWord();
			continue; // 继续处理下一行
		case 'f': // 面信息
			// 解析面信息并添加到currentGroup中
			this.parseFace(sp, currentGroup);
			continue; // 继续处理下一行
		}
	}
	this.complete = true;
	console.log("OBJ文件" + this.fileName + "内容读取完毕");
	return true;
}

// 解析面信息并添加到currentGroup中
OBJModel.prototype.parseFace = function(sp, currentGroup) {
	//console.log(currentGroup.name + "面信息");
	var vIndices = new Array(0); // 顶点坐标索引数组
	var tIndices = new Array(0); // 顶点纹理坐标索引数组
	var nIndices = new Array(0); // 顶点法向数组
	// 获取面索引信息
	for(;;){
		var word = sp.getWord();
		if(word == null) break;  // 获取word为空则此行解析完毕
		//console.log(word);
		//alert("ok");
		var subWords = word.split('/');
		if(subWords.length >= 1){
			// 顶点坐标(减1是因为obj文件里顶点编号从1开始)
			var vi = parseInt(subWords[0]) - 1;
			if(isNaN(vi))
				break;
			vIndices.push(vi);
		}
		if(subWords.length >= 2){
			// 纹理坐标
			if(subWords[1] != ""){
				var ti = parseInt(subWords[1]) - 1;
				tIndices.push(ti); 
			}
		}
		if(subWords.length >= 3){
			// 法向
			if(subWords[2] != ""){
				var ni = parseInt(subWords[2]) - 1;
				nIndices.push(ni); 
			}
		}
	}
	
	// 如果构成face的顶点数大于3，则要拆分成多个三角形
	if(vIndices.length > 3){
		//console.log("存在面顶点数超过3的情况：%d", vIndices.length);
		//console.log("%d %d %d %d", vIndices[0], vIndices[1], vIndices[2], vIndices[3]);
		var n = vIndices.length - 2; // 3角形数
		var newVIndices = new Array(n * 3);
		if(tIndices.length > 0)
			var newTIndices = new Array(n * 3);
		if(nIndices.length > 0)
			var newNIndices = new Array(n * 3);
		for(var i = 0; i < n; i++){
			newVIndices[i * 3 + 0] = vIndices[0];
			newVIndices[i * 3 + 1] = vIndices[i + 1];
			newVIndices[i * 3 + 2] = vIndices[i + 2];
			if(tIndices.length > 0){
				newTIndices[i * 3 + 0] = tIndices[0];
				newTIndices[i * 3 + 1] = tIndices[i + 1];
				newTIndices[i * 3 + 2] = tIndices[i + 2];
			}
			if(nIndices.length > 0){
				newNIndices[i * 3 + 0] = nIndices[0];
				newNIndices[i * 3 + 1] = nIndices[i + 1];
				newNIndices[i * 3 + 2] = nIndices[i + 2];
			}
		}
		vIndices = newVIndices;
		if(tIndices.length > 0)
			tIndices = newTIndices;
		if(nIndices.length > 0)
			nIndices = newNIndices;
	}
	
	// 将顶点数据添加到Group对象中
	for(var i = 0; i < vIndices.length; i++){
		currentGroup.vertices.push(this.vertices[vIndices[i]]);
		if(tIndices.length > 0)
			currentGroup.texcoords.push(this.texcoords[tIndices[i]]);
		if(nIndices.length > 0)
			currentGroup.normals.push(this.normals[nIndices[i]]);
	}
}

// 获取mtllib文件名
OBJModel.prototype.parseMtllib = function(sp, fileName) {
	// 获取目录路径
	var i = fileName.lastIndexOf("\\");
	var dirPath = "";
	if(i > 0) dirPath = fileName.substr(0, i+1);

	return dirPath + sp.getRemain(); // 得到完整路径
}

// 是否一切就绪，可以绘制了？
OBJModel.prototype.isAllReady = function(gl) {
	// 如果obj相关文件信息读取完毕,但绘制准备工作还未做
	if(!this.ready && this.isComplete()){
		// 为绘制做准备，例如初始化纹理对象、
		// 查找各Group对象所使用材质、初始化顶点缓存对象
		this.onReadComplete(gl);
		this.ready = true; // 此时一切就绪了
	}
	
	return this.ready;
}

// 是否相关信息已全部加载完毕
OBJModel.prototype.isComplete = function() {
	if(this.complete && this.mtllib.isComplete())
		return true;
	else
		return false;
}

// 全部信息读取完成后，为绘制做准备
OBJModel.prototype.onReadComplete = function(gl){
	console.log(this.fileName + "相关文件全部读取完毕");
	
	// 初始化纹理对象
	this.mtllib.initTextures(gl);
	
	console.log("查找Group对象材质及初始化顶点缓存对象");
	for(var i = 0; i < this.groups.length; i++){
		// 根据group对象的材质名称查找材质对象
		this.groups[i].material = 
			this.mtllib.findMTL(this.groups[i].mtlName);
		// 初始化各缓存对象
		this.groups[i].initBuffers(gl);
	}
	
	// 释放空间
	this.vertices.length = 0;
	this.normals.length = 0;
	this.texcoords.length = 0;
}

// 绘制OBJ模型，后面3个参数分别为shader中顶点属性变量索引、
// uniform材质变量索引和纹理采样器索引
OBJModel.prototype.draw = function(gl, attribIndex, mtlIndex, u_Sampler){
	if(attribIndex == null) return;
	for(var i = 0; i < this.groups.length; i++){
		this.groups[i].draw(gl, attribIndex, mtlIndex, u_Sampler);
	}
}

// 请求加载模型文件
function loadMTL(mtlLib){
	var request = new XMLHttpRequest();

	request.onreadystatechange = function() {
		if (request.readyState === 4 && request.status !== 404) {
			console.log(mtlLib.fileName + "加载完毕");
			onReadMTLFile(request.responseText, mtlLib);
		}
		else if(request.status === 404) // 文件找不到
			console.log("mtl文件加载失败：" + mtlLib.fileName);
	}
	// 创建获取文件的请求，最后一个参数表示采用异步方式
	request.open('GET', mtlLib.fileName, true); 
	request.send();  // 发送请求  
	console.log("开始加载材质文件：" + mtlLib.fileName);
}

function onReadMTLFile(fileString, mtlLib){
	mtlLib.readMTLFile(fileString);
}

// Group对象
// 构造函数(参数为Group对象名称)
var Group = function(name) {
	this.name = name;				 // Group对象名称
	this.mtlName = null;      	 	 // 使用材质名称
	this.material = new Material(null);  // 使用材质，初始化为默认材质
	this.vertices = new Array(0);	 // 顶点坐标数组，初始为空
	this.normals = new Array(0);	 // 顶点法向数组，初始为空
	this.texcoords = new Array(0); 	 // 顶点纹理坐标数组，初始为空
	
	this.vBuffer = null;	// 顶点坐标buffer对象
	this.tBuffer = null;	// 顶点纹理坐标buffer对象
	this.nBuffer = null;	// 顶点法向buffer对象
	this.numVertices = 0;	// 顶点数，初始化为0
}

// 绘制Group对象，后面3个参数分别为shader中顶点属性变量索引、
// uniform材质变量索引和纹理采样器索引
Group.prototype.draw = function(gl, attribIndex, mtlIndex, u_Sampler){
	if(attribIndex == null) return; 
	// 为a_Position提供数据
	if(attribIndex.a_Position != -1 && this.vBuffer != null){
		gl.bindBuffer(gl.ARRAY_BUFFER, this.vBuffer);
		gl.vertexAttribPointer( 
			attribIndex.a_Position,	// 属性变量索引
			3,					// 每个顶点属性的分量个数
			gl.FLOAT,			// 数组数据类型
			false,				// 是否进行归一化处理
			0,   // 在数组中相邻属性成员起始位置间的间隔(以字节为单位)
			0    // 第一个属性值在buffer中的偏移量
		);
		gl.enableVertexAttribArray(attribIndex.a_Position);
	}
	
	// 为a_Texcoord提供数据
	if(attribIndex.a_Texcoord != -1 && this.tBuffer != null){
		gl.bindBuffer(gl.ARRAY_BUFFER, this.tBuffer);
		gl.vertexAttribPointer( 
			attribIndex.a_Texcoord,	// 属性变量索引
			2,					// 每个顶点属性的分量个数
			gl.FLOAT,			// 数组数据类型
			false,				// 是否进行归一化处理
			0,   // 在数组中相邻属性成员起始位置间的间隔(以字节为单位)
			0    // 第一个属性值在buffer中的偏移量
		);
		gl.enableVertexAttribArray(attribIndex.a_Texcoord);
	}
	
	// 为a_Normal提供数据
	if(attribIndex.a_Normal != -1 && this.nBuffer != null){
		gl.bindBuffer(gl.ARRAY_BUFFER, this.nBuffer);
		gl.vertexAttribPointer( 
			attribIndex.a_Normal,	// 属性变量索引
			3,					// 每个顶点属性的分量个数
			gl.FLOAT,			// 数组数据类型
			false,				// 是否进行归一化处理
			0,   // 在数组中相邻属性成员起始位置间的间隔(以字节为单位)
			0    // 第一个属性值在buffer中的偏移量
		);
		gl.enableVertexAttribArray(attribIndex.a_Normal);
	}
	
	// 为uniform材质变量传值
	if(mtlIndex != null){
		if(mtlIndex.u_Kd) // 漫反射系数
			gl.uniform3f(mtlIndex.u_Kd, this.material.Kd[0], 
				this.material.Kd[1], this.material.Kd[2]);
		if(mtlIndex.u_Ks) // 镜面反射系数
			gl.uniform3f(mtlIndex.u_Ks, this.material.Ks[0], 
				this.material.Ks[1], this.material.Ks[2]);
		if(mtlIndex.u_Ka) // 环境反射系数
			gl.uniform3f(mtlIndex.u_Ka, this.material.Ka[0], 
				this.material.Ka[1], this.material.Ka[2]);
		if(mtlIndex.u_Ke) // 发射系数
			gl.uniform3f(mtlIndex.u_Ke, this.material.Ke[0], 
				this.material.Ke[1], this.material.Ke[2]);
		if(mtlIndex.u_Ns) // 高光系数
			gl.uniform1f(mtlIndex.u_Ns, this.material.Ns);
		if(mtlIndex.u_d)  // 不透明度
			gl.uniform1f(mtlIndex.u_d, this.material.d);
	}

	// 为u_Sampler传值
	if(u_Sampler != null && this.material.texture != null){
		gl.activeTexture(gl.TEXTURE0);
		// 绑定纹理对象到目标上
		gl.bindTexture(gl.TEXTURE_2D, this.material.texture);
		// 使用0号纹理单元，这里不考虑多纹理单元情况
		gl.uniform1i(u_Sampler, 0); 
	}
	
	gl.drawArrays(gl.TRIANGLES, 0, this.numVertices);
}

// 初始化顶点buffer对象
Group.prototype.initBuffers = function(gl){
	console.log("开始初始化Group对象" + this.name + "的buffer");
	console.log("顶点数：%d", this.vertices.length);
	if(this.vertices.length == 0)
		return;
	// 初始化顶点坐标buffer对象
	this.vBuffer = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, this.vBuffer);
	gl.bufferData(gl.ARRAY_BUFFER,	// Buffer类型
		flatten(this.vertices),		// 数据来源
		gl.STATIC_DRAW	// 表明是一次提供数据，多遍绘制
	);
	this.numVertices = this.vertices.length; // 顶点数
	this.vertices.length = 0; // 释放空间
	
	// 初始化顶点纹理坐标buffer对象
	if(this.texcoords.length > 0){
		this.tBuffer = gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER, this.tBuffer);
		gl.bufferData(gl.ARRAY_BUFFER,	// Buffer类型
			flatten(this.texcoords),	// 数据来源
			gl.STATIC_DRAW	// 表明是一次提供数据，多遍绘制
		);
		this.texcoords.length = 0; // 释放空间
	}
	
	// 初始化顶点法向buffer对象
	if(this.normals.length > 0){
		this.nBuffer = gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER, this.nBuffer);
		gl.bufferData(gl.ARRAY_BUFFER,	// Buffer类型
			flatten(this.normals),	// 数据来源
			gl.STATIC_DRAW	// 表明是一次提供数据，多遍绘制
		);
		this.normals.length = 0; // 释放空间
	}
}

// MTLLib对象
// 构造函数(参数为材质文件路径)
var MTLLib = function(fileName) {
	this.fileName = fileName;
	this.materials = new Array(0); // 材质数组，初始为空
	this.textures = new Array(0);  // 纹理对象数组，初始为空
	this.complete = false;		 // 材质文件是否读取完毕
}

// 读取mtl文件内容
MTLLib.prototype.readMTLFile = function(fileString){
	console.log("开始读取MTL文件" + this.fileName + "内容");
	// 用换行符对文件进行切分，即获取每一行内容，存为数组
	var lines = fileString.split('\n');  
	lines.push(null); // 添加一个null数组元素，作为结束标志
	var index = 0;    // lines数组下标

	// 逐行进行解析
	var newMTL = null; // 新材质对象
	var line;  // 存储待解析的一行字符
	var sp = new StringParser();  // 创建字符串解析器
	var r, g, b;	// 临时变量
	while ((line = lines[index++]) != null) {
		sp.init(line);    			// 初始化StringParser
		var command = sp.getWord(); // 获取当前行的指令
		if(command == null)	 continue;  // 当前行为空行

		switch(command){
		case '#':
			continue;    // 跳过注释
		case 'newmtl': 	 // 新材质名称行
			// 获取新材质名称并创建新的材质对象
			newMTL = new Material(sp.getWord());
			this.materials.push(newMTL);	// 添加到材质数组里
			continue; // 继续处理下一行
		case 'Kd':   // 漫反射系数
			r = sp.getFloat();
			g = sp.getFloat();
			b = sp.getFloat();
			newMTL.Kd = vec3(r, g, b);
			continue; // 继续处理下一行
		case 'Ks':   // 镜面反射系数
			r = sp.getFloat();
			g = sp.getFloat();
			b = sp.getFloat();
			newMTL.Ks = vec3(r, g, b);
			continue; // 继续处理下一行
		case 'Ka':   // 环境反射系数
			r = sp.getFloat();
			g = sp.getFloat();
			b = sp.getFloat();
			newMTL.Ka = vec3(r, g, b);
			continue; // 继续处理下一行
		case 'Ke':   // 发射系数
			r = sp.getFloat();
			g = sp.getFloat();
			b = sp.getFloat();
			newMTL.Ke = vec3(r, g, b);
			continue; // 继续处理下一行
		case 'Ns':	// 高光系数
			newMTL.Ns = sp.getFloat();
			continue; // 继续处理下一行
		case 'd':   // 不透明度
			newMTL.d = sp.getFloat();
			continue; // 继续处理下一行
		case 'map_Kd': // 漫反射贴图
			// 获取漫反射贴图文件名
			var path = this.parseMapKd(sp, this.fileName);
			newMTL.map_Kd = path;
			if(this.findTexture(path) != null)	// 已加载过此纹理图？
				continue;
			var newTex = new Texture(path);
			this.textures.push(newTex);
			loadImg(newTex, path); // 加载纹理图
			continue; // 继续处理下一行
		}
	}
	console.log("材质文件" + this.fileName + "读取完毕");
	this.complete = true;
}

// 加载纹理图
function loadImg(newTex, path){
	newTex.image = new Image(); // 新建图像对象
			
	// 加载完成后调用此函数
	newTex.image.onload = function(){
		newTex.complete = true;
		console.log("纹理图" + path + "加载完毕");
	}
	
	// 开始加载图像
	newTex.image.src = path;
	console.log("开始加载纹理图" + path);
}

// 获取漫反射贴图文件名
MTLLib.prototype.parseMapKd = function(sp, fileName) {
	// 获取目录路径
	var i = fileName.lastIndexOf('\\');
	var dirPath = "";
	if(i > 0) dirPath = fileName.substr(0, i+1);

	return dirPath + sp.getRemain(); // 得到完整路径
}

// MTLLib文件是否已全部加载完毕
MTLLib.prototype.isComplete = function() {
	if(this.complete == false)
		return false;
	for(var i = 0; i < this.textures.length; i++){
		if(this.textures[i].complete == false)
			return false;
	}
	return true;
}

// 根据材质名查找材质对象
MTLLib.prototype.findMTL = function(name){
	for(var i = 0; i < this.materials.length; i++){
		if(this.materials[i].name == name)
			return(this.materials[i]);
    }
	
	return(new Material(null));
}

// 根据纹理图像路径名查找Texture对象
MTLLib.prototype.findTexture = function(name){
	for(var i = 0; i < this.textures.length; i++){
		if(this.textures[i].pathName == name)
			return(this.textures[i]);
    }
	
	return null;
}

// 初始化纹理对象
MTLLib.prototype.initTextures = function(gl){
	console.log("初始化纹理对象");
	for(var i = 0; i < this.textures.length; i++){
		this.textures[i].initTexture();
	}
	for(var i = 0; i < this.materials.length; i++){
		if(this.materials[i].map_Kd == null)
			continue;
		this.materials[i].texture = 
			this.findTexture(this.materials[i].map_Kd).texture;
	}
}

// Texture对象
var Texture = function(pathName){
	this.pathName = pathName;	// 纹理图路径名
	this.image = null;			// image对象
	this.complete = false;		// 纹理图是否加载完毕
	this.texture = null;		// WebGL纹理对象
}

// 加载纹理图
Texture.prototype.initTexture = function(){
	if(this.image == null || this.complete == false)
		return;
	
	this.texture = gl.createTexture(); // 创建纹理对象
	
	// 绑定纹理对象到目标上
	gl.bindTexture(gl.TEXTURE_2D, this.texture);
	
	// 对纹理图像进行y轴反转
	gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, 1); 
	
	// 配置纹理图像
	gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, this.image);
	// 自动生成各级分辨率的纹理图
	gl.generateMipmap(gl.TEXTURE_2D); 
	
	// 设置插值参数
	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
}


// Material对象
// 构造函数
var Material = function(materialName){
	this.name = materialName;		 // 材质名称
	this.Kd = vec3(1.0, 1.0, 1.0);	 // 漫反射系数
	this.Ks = vec3(0.0, 0.0, 0.0);	 // 镜面反射系数
	this.Ka = vec3(0.2, 0.2, 0.2);	 // 环境反射系数
	this.Ke = vec3(0.0, 0.0, 0.0);	 // 发射系数
	this.Ns = 10;	// 高光系数
	this.d = 1.0;	// 不透明度，默认完全不透明
	this.map_Kd = null;	// 漫反射贴图
	this.texture = null;	// 纹理对象，初始为空
}

//------------------------------------------------------------------------------
// 字符串解析器对象
// 构造函数
var StringParser = function(str) {
	this.str;   // 待解析字符串
	this.index; // 字符串中处理到的位置
	this.init(str);
}

// 初始化StringParser对象
StringParser.prototype.init = function(str){
	this.str = str;
	this.index = 0;
}

// 从当前位置开始，跳过分隔符
StringParser.prototype.skipDelimiters = function(){
	var i = this.index;
	for(len = this.str.length; i < len; i++){
		var c = this.str.charAt(i);
		// 跳过TAB、空格、以及左右括号
		if (c == '\t'|| c == ' ' || c == '(' || c == ')' || c == '"') 
			continue;
		break;
	}
	this.index = i;
}

// 获取下一个word
StringParser.prototype.getWord = function(){
	this.skipDelimiters(); // 跳过分隔符
	// 获取Word的长度
	var n = getWordLength(this.str, this.index);
	if (n == 0) return null; // 没有待处理的word了
	var word = this.str.substr(this.index, n);
	this.index += (n + 1);

	return word;
}

// 获取当前行剩余的字符(除去末尾的空字符)
StringParser.prototype.getRemain = function(){
	this.skipDelimiters(); // 跳过分隔符
	
	// 去掉末尾的空字符
	var endIndex;
	for(endIndex = this.str.length - 1; endIndex > this.index; endIndex--){
		var c = this.str.charAt(endIndex);
		// 跳过TAB、空格、以及左右括号
		if (c == '\t'|| c == ' ' || c == '(' || c == ')' || c == '"') 
			continue;
		break;
	}
	
	if(endIndex == this.index)
		return null;
	
	var word = this.str.substr(this.index, endIndex);
	this.index += (endIndex + 1);
	
	return word;
}

// 获取一个Float
StringParser.prototype.getFloat = function() {
	return parseFloat(this.getWord());
}

// 获取Word的长度
function getWordLength(str, start) {
	var i = start;
	for(len = str.length; i < len; i++){
		var c = str.charAt(i);
		if (c == '\t'|| c == ' ' || c == '(' || c == ')' || c == '"') 
			break;
	}
	return i - start;
}

// 顶点属性Index对象
// 存放shader中对应顶点attribute变量的索引
// 构造函数
var AttribIndex = function(){
	this.a_Position = -1;	 // 顶点坐标索引
	this.a_Normal   = -1;	 // 顶点法向索引
	this.a_Texcoord = -1;	 // 顶点纹理坐标索引
}

// 如果shader中没有相关变量则传-1
AttribIndex.prototype.init = function(a_Position, a_Normal, a_Texcoord){
	this.a_Position = a_Position; 	// 顶点坐标索引
	this.a_Texcoord = a_Texcoord;	// 顶点法向索引
	this.a_Normal = a_Normal;		// 顶点纹理坐标索引
}

// Material Index对象
// 存放shader中对应uniform材质变量的索引
// 构造函数
var MTLIndex = function(){
	this.u_Kd = 0;	 // 漫反射系数索引
	this.u_Ks = 0;	 // 镜面反射系数索引
	this.u_Ka = 0;	 // 环境反射系数索引
	this.u_Ke = 0;	 // 发射系数索引
	this.u_Ns = 0;	 // 高光系数索引
	this.u_d  = 0;	 // 不透明度索引
}

// 如果shader中没有相关变量则传0
MTLIndex.prototype.init = function(u_Kd, u_Ks, u_Ka, u_Ke, u_Ns, u_d){
	this.u_Kd = u_Kd;	 // 漫反射系数索引
	this.u_Ks = u_Ks;	 // 镜面反射系数索引
	this.u_Ka = u_Ka;	 // 环境反射系数索引
	this.u_Ke = u_Ke;	 // 发射系数索引
	this.u_Ns = u_Ns;	 // 高光系数索引
	this.u_d  = u_d;	 // 不透明度索引
}