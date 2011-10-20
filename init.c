#include "TH.h"
#include "luaT.h"

#include "stdint.h"
#include "mccodimage.h"
#include "mcimage.h"
#include "jcimage.h"
#include "jccodimage.h"
#include "llabelextrema.h"
#include "lwshedtopo.h"
#include "lsaliency.h"
#include "lhierarchie.h"
#include "lga2khalimsky.h"
#include "lppm2GA.h"
#include "set.h"

#define torch_(NAME) TH_CONCAT_3(torch_, Real, NAME)
#define torch_string_(NAME) TH_CONCAT_STRING_3(torch., Real, NAME)
#define imgraph_(NAME) TH_CONCAT_3(imgraph_, Real, NAME)

static const void* torch_FloatTensor_id = NULL;
static const void* torch_DoubleTensor_id = NULL;

#include "generic/imgraph.c"
#include "THGenerateFloatTypes.h"

DLL_EXPORT int luaopen_libimgraph(lua_State *L)
{
  torch_FloatTensor_id = luaT_checktypename2id(L, "torch.FloatTensor");
  torch_DoubleTensor_id = luaT_checktypename2id(L, "torch.DoubleTensor");

  imgraph_FloatInit(L);
  imgraph_DoubleInit(L);

  return 1;
}
