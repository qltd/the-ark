(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var body = $('body')
        , navigation = $('.menu-primary-wrapper')
        , toggle = $('.header-navigation-primary .block__title')
        , buttonClose = $('.menu-primary-close');
      if (navigation.length === 0 || toggle.length === 0 || buttonClose.length === 0) return;

      var toggleClasses = function (method) {
        body[method]('document-no-scroll');
        toggle[method]('active');
        navigation[method]('menu-flyout-visible');
        switch (method) {
          case 'addClass':
            $(document).bind('touchmove', function (e) {
              e.preventDefault();
            });
            break;
          case 'removeClass':
            $(document).off('touchmove');
            break;
        }
      };

      navigation.bind('touchmove', function (e) {
        e.stopPropagation();
      });

      body.bind('swiperight', function () {
        toggleClasses('addClass');
      });
      navigation.bind('swipeleft', function () {
        toggleClasses('removeClass');
      });
      toggle.bind('tap', function () {
        toggleClasses('addClass');
      });
      buttonClose.bind('tap', function () {
        toggleClasses('removeClass');
      });
    }
  };
})(jQuery);
