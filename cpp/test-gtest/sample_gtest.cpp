#include <gtest/gtest.h>
#include "ISingleSignOnRegistry.h"
#include "MyService.h"
#include "SSOToken.h"
#include "Request.h"
#include "Response.h"
#include "SingleSignOnRegistryTestDouble.h"
#include "SingleSignOnRegistry.h"

using namespace std;

TEST(MyServiceTest, validTokenIsAccepted) {
    auto registry = new SingleSignOnRegistry(new AuthenticationGateway());
    auto service = new MyService(registry);
    auto token = new SSOToken();
    auto response = service->handleRequest(new Request("Name", token));
    ASSERT_EQ("hello Name!", response->getText());
}