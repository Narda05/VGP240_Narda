#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pin<0,1,2,3>

#line 504 "D:\Gith\VGP240_Narda\Pix\X\External\DirectXTK\src\Shaders\BasicEffect.fx"
    mov oC0, t0  // ::PSBasicNoFog<0,1,2,3>

// approximately 1 instruction slot used
ps_4_0
dcl_input_ps linear v0.xyzw
dcl_output o0.xyzw
mov o0.xyzw, v0.xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE BasicEffect_PSBasicNoFog[] =
{
     68,  88,  66,  67,  94,  90, 
    166,  76,  66,  65, 171, 127, 
    101,  55, 129, 142, 206, 114, 
     24, 209,   1,   0,   0,   0, 
    108,   2,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    200,   1,   0,   0,   8,   2, 
      0,   0,  56,   2,   0,   0, 
     65, 111, 110,  57, 144,   1, 
      0,   0, 144,   1,   0,   0, 
      0,   2, 255, 255, 108,   1, 
      0,   0,  36,   0,   0,   0, 
      0,   0,  36,   0,   0,   0, 
     36,   0,   0,   0,  36,   0, 
      0,   0,  36,   0,   0,   0, 
     36,   0,   0,   2, 255, 255, 
    254, 255,  82,   0,  68,  66, 
     85,  71,  40,   0,   0,   0, 
     28,   1,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    116,   0,   0,   0,   2,   0, 
      0,   0, 120,   0,   0,   0, 
      2,   0,   0,   0, 244,   0, 
      0,   0, 136,   0,   0,   0, 
     68,  58,  92,  71, 105, 116, 
    104,  92,  86,  71,  80,  50, 
     52,  48,  95,  78,  97, 114, 
    100,  97,  92,  80, 105, 120, 
     92,  88,  92,  69, 120, 116, 
    101, 114, 110,  97, 108,  92, 
     68, 105, 114, 101,  99, 116, 
     88,  84,  75,  92, 115, 114, 
     99,  92,  83, 104,  97, 100, 
    101, 114, 115,  92,  66,  97, 
    115, 105,  99,  69, 102, 102, 
    101,  99, 116,  46, 102, 120, 
      0, 171, 171, 171,  40,   0, 
      0,   0,   0,   0, 255, 255, 
     80,   1,   0,   0, 248,   1, 
      0,   0,  92,   1,   0,   0, 
     80,  83,  66,  97, 115, 105, 
     99,  78, 111,  70, 111, 103, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0, 112, 105, 110,   0, 
     68, 105, 102, 102, 117, 115, 
    101,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    184,   0,   0,   0, 192,   0, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   4,   0,   1,   0, 
      1,   0, 208,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
      0,   0,   0,   0, 136,   0, 
      0,   0, 152,   0,   0,   0, 
      1,   0,   0,   0, 168,   0, 
      0,   0, 136,   0,   0,   0, 
    180,   0,   0,   0, 216,   0, 
      0,   0,   1,   0,   0,   0, 
    232,   0,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 176,   1,   0,   0,   2, 
      0,   8,  15, 128,   0,   0, 
    228, 176, 255, 255,   0,   0, 
     83,  72,  68,  82,  56,   0, 
      0,   0,  64,   0,   0,   0, 
     14,   0,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      0,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      0,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  73,  83, 
     71,  78,  40,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,  15, 
      0,   0,  67,  79,  76,  79, 
     82,   0, 171, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171
};
