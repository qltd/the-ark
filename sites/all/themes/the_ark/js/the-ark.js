(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({1:[function(require,module,exports){
/**
 *
 *   sdSS_SSSSSSbs   .S    S.     sSSs         .S_SSSs     .S_sSSs     .S    S.
 *   YSSS~S%SSSSSP  .SS    SS.   d%%SP        .SS~SSSSS   .SS~YS%%b   .SS    SS.
 *        S%S       S%S    S%S  d%S'          S%S   SSSS  S%S   `S%b  S%S    S&S
 *        S%S       S%S    S%S  S%S           S%S    S%S  S%S    S%S  S%S    d*S
 *        S&S       S%S SSSS%S  S&S           S%S SSSS%S  S%S    d*S  S&S   .S*S
 *        S&S       S&S  SSS&S  S&S_Ss        S&S  SSS%S  S&S   .S*S  S&S_sdSSS
 *        S&S       S&S    S&S  S&S~SP        S&S    S&S  S&S_sdSSS   S&S~YSSY%b
 *        S&S       S&S    S&S  S&S           S&S    S&S  S&S~YSY%b   S&S    `S%
 *        S*S       S*S    S*S  S*b           S*S    S&S  S*S   `S%b  S*S     S%
 *        S*S       S*S    S*S  S*S.          S*S    S*S  S*S    S%S  S*S     S&
 *        S*S       S*S    S*S   SSSbs        S*S    S*S  S*S    S&S  S*S     S&
 *        S*S       SSS    S*S    YSSP        SSS    S*S  S*S    SSS  S*S     SS
 *        SP               SP                        SP   SP          SP
 *        Y                Y                         Y    Y           Y
 *             _                                         _        _ _
 *            | |                                       (_)      | (_)
 *   __      _| |__   ___ _ __ ___   _ __ ___  _   _ ___ _  ___  | |___   _____  ___
 *   \ \ /\ / / '_ \ / _ \ '__/ _ \ | '_ ` _ \| | | / __| |/ __| | | \ \ / / _ \/ __|
 *    \ V  V /| | | |  __/ | |  __/ | | | | | | |_| \__ \ | (__  | | |\ V /  __/\__ \
 *     \_/\_/ |_| |_|\___|_|  \___| |_| |_| |_|\__,_|___/_|\___| |_|_| \_/ \___||___/
 *
 */
/*
  Browserify/Uglify Generated JavaScript for the Ark -- https://github.com/qltd/the-ark

  - compile while in .npm directory (sites/all/themes/the_ark/.npm)           : gulp js
  - watch for changes while in .npm directory (sites/all/themes/the_ark/.npm) : gulp watch
*/

/**
 * Configuration
 */
require('./config/facebook');
require('./config/headroom');
require('./config/twitter');

/**
 * Components
 */
require('./behaviors/calendar');
require('./behaviors/columned-text');
require('./behaviors/expandable-details');
require('./behaviors/events-upcoming');
require('./behaviors/expander');
require('./behaviors/footer-contact');
require('./behaviors/header-navigation-primary');
require('./behaviors/header-search');
require('./behaviors/tabs');
require('./behaviors/video');

},{"./behaviors/calendar":2,"./behaviors/columned-text":3,"./behaviors/events-upcoming":4,"./behaviors/expandable-details":5,"./behaviors/expander":6,"./behaviors/footer-contact":7,"./behaviors/header-navigation-primary":8,"./behaviors/header-search":9,"./behaviors/tabs":10,"./behaviors/video":11,"./config/facebook":12,"./config/headroom":13,"./config/twitter":14}],2:[function(require,module,exports){
(function ($) {

  function togglePastEventsText (action) {
    return 'Click to ' + action + ' Past Events';
  }

  Drupal.behaviors.theArkCalendar = {
    attach: function () {
      var container = $('.calendar-body');
      if (container.length === 0) return;

      var dateNav = $('.date-nav').clone();
      dateNav.children('.date-heading').remove();
      container.append(dateNav);

      var today = container.find('.today');
      if (today.length === 0) return;

      var past = container.find('.past');
      if (past.length === 0) return;

      var toggleContainer = $('<div class="show-past-toggle-container"></div>')
        , toggle = $('<a class="show-past-toggle" role="button"></div>');

      toggle.text(togglePastEventsText('Show'));
      toggleContainer.append(toggle);
      container.prepend(toggleContainer);
      past.addClass('past-hidden');

      toggle.on('tap', function () {
        if (past.hasClass('past-hidden')) {
          past.removeClass('past-hidden');
          toggle.text(togglePastEventsText('Hide'));
        } else {
          past.addClass('past-hidden');
          toggle.text(togglePastEventsText('Show'));
        }
      });
    }
  };
})(jQuery);

},{}],3:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkColumnedText = {
    attach: function () {
      var item = $('.columned-text-item');
      if (item.length === 0) return;

      var headings = item.find('h3, h4, h5, h6');
      headings.each(function (index) {
        var self = $(this)
          , sibling = self.next();

        if (!sibling.length) return;
        var replacement = $('<div class="title-content-pair"></div>').html(self.clone());
        replacement.append(sibling.clone());
        sibling.after(replacement);
        self.remove();
        sibling.remove();
      });
    }
  };
})(jQuery);

},{}],4:[function(require,module,exports){
(function ($) {

  function toggleUpcomingEventsText (action) {
    return 'Click to ' + action + ' More Upcoming Events';
  }

  Drupal.behaviors.theArkEventsUpcoming = {
    attach: function () {
      var container = $('.events-upcoming-view')
        , events = $('.calendar-column').not('.first');
      if (container.length === 0 || events.length === 0) return;

      var toggleContainer = $('<div class="show-upcoming-toggle-container"></div>')
        , toggle = $('<a class="show-upcoming-toggle" role="button"></div>');

      toggle.text(toggleUpcomingEventsText('Show'));
      toggleContainer.append(toggle);
      container.append(toggleContainer);
      events.addClass('upcoming-hidden');

      toggle.on('tap', function () {
        if (events.hasClass('upcoming-hidden')) {
          events.removeClass('upcoming-hidden');
          toggle.text(toggleUpcomingEventsText('Hide'));
        } else {
          events.addClass('upcoming-hidden');
          toggle.text(toggleUpcomingEventsText('Show'));
        }
      });
    }
  };
})(jQuery);

},{}],5:[function(require,module,exports){
(function ($) {

  function expandableDetailsToggle (elem) {
    var parent = elem.parents('.expandable-details-item')
      , expander = parent.find('.expandable-details-expander')
      , expanderLabel = expander.length && expander.attr('data-expander-label') ?
          expander.attr('data-expander-label') :
          'Item';

    if (parent.hasClass('expandable-details-item-collapsed'))
      expander.text('Close ' + expanderLabel);
    else
      expander.text('View ' + expanderLabel);

    parent.toggleClass('expandable-details-item-collapsed');
  }

  Drupal.behaviors.theArkExpandableDetails = {
    attach: function () {
      var expanders = $('.expandable-details-title, .expandable-details-expander')
        , items = $('.expandable-details-item');

      if (!expanders.length || !items.length) return;

      $('.expandable-details-expander').each(function (index, expander) {
        expandableDetailsToggle($(expander));
      });

      expanders.on('tap', function () {
        expandableDetailsToggle($(this));
      });
    }
  };
})(jQuery);

},{}],6:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkExpander = {
    attach: function () {
      var expanders = $('.expander');
      if (expanders.length === 0) return;

      expanders.addClass('expander-collapsed');
      expanders.on('tap', function () {
        $(this).toggleClass('expander-collapsed');
        Drupal.behaviors.theArkVideo.attach();
      });
    }
  };
})(jQuery);

},{}],7:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkFooterContact = {
    attach: function () {
      var block = $('.footer-contact')
        , phoneNumbers = $('.footer-contact .phone');
      if (block.length === 0 || phoneNumbers.length === 0) return;

      phoneNumbers.each(function () { // ensure href for each phone link points to the correct phone number
        var number = $(this).text();
        if (!number) return;
        $(this).attr('href', 'tel:+' + number.replace(/\D/g,''));
      });
    }
  };
})(jQuery);

},{}],8:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var body = $('body')
        , wrapper = $('.menu-primary-wrapper')
        , navigation = $('.menu-primary-wrapper > .menu')
        , toggle = $('.header-navigation-primary .block__title')
        , buttonClose = $('.menu-primary-close');
      if (wrapper.length === 0 || navigation.length === 0) return;

      var toggleClasses = function (method) {
        body[method]('document-modal-mobile');
        toggle[method]('active');
        wrapper[method]('menu-flyout-visible');
        switch (method) {
          case 'addClass':
            toggle.off('tap');

            $(document).on('touchmove', function (e) {
              e.preventDefault();
            });
            navigation.on('touchmove', function (e) {
              e.stopPropagation();
            });
            buttonClose.on('tap', function () {
              toggleClasses('removeClass');
            });

            break;
          case 'removeClass':
            $(document).off('touchmove');
            navigation.off('touchmove');
            buttonClose.off('tap');

            defaultListeners();
            break;
        }
      };

      var defaultListeners = function () {
        toggle.on('tap', function () {
          toggleClasses('addClass');
        });
      };
      defaultListeners();

    }
  };
})(jQuery);

},{}],9:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkHeaderSearch = {
    attach: function () {
      var block = $('.header-search')
        , doc = $(document)
        , form = $('.header-search .search-block-form')
        , submit = $('.header-search .form-submit')
        , text = $('.header-search .form-text')
        , textContainer = $('.header-search .form-type-textfield');

      if (block.length === 0) return;

      submit.on('tap', function (event) {
        event.preventDefault();
        event.stopPropagation();

        if (textContainer.hasClass('form-type-textfield-active')) {
          textContainer.removeClass('form-type-textfield-active');
        } else {
          textContainer.addClass('form-type-textfield-active');
          text.focus();

          doc.on('tap', function (event) {
            textContainer.removeClass('form-type-textfield-active');
            doc.off('tap');
          });
        }
      });

      submit.on('click', function (event) {
        event.preventDefault();
        if (text.val()) form.submit();
        else if (textContainer.hasClass('form-type-textfield-active')) text.focus();
      });

      text.on('tap', function (event) {
        event.stopPropagation();
      });
    }
  };
})(jQuery);

},{}],10:[function(require,module,exports){
(function ($) {
  function tabToggle (tabId, containers, toggles) {
    toggles.removeClass('tab-toggle-active');
    containers.removeClass('tab-container-active');

    toggles.filter('[data-tab-toggle-id="' + tabId + '"]').addClass('tab-toggle-active');
    containers.filter('[data-tab-id="'+ tabId +'"]').addClass('tab-container-active');
  }

  Drupal.behaviors.theArkTabs = {
    attach: function () {
      var containers = $('.tab-container')
        , toggles = $('.tab-toggle');
      if (containers.length === 0 || toggles.length === 0) return;

      tabToggle($(toggles[0]).attr('data-tab-toggle-id'), containers, toggles);

      toggles.on('click', function (e) {
        e.preventDefault();
      });

      toggles.on('tap', function () {
        var tabId = $(this).attr('data-tab-toggle-id');
        if (!tabId) return;
        tabToggle(tabId, containers, toggles);
      });
    }
  };
})(jQuery);

},{}],11:[function(require,module,exports){
(function ($) {
  var resizeMedia = function (videos) {
    var i = videos.length;
    while (i--) {
      var width = parseInt(videos[i].width || 0)
        , height = parseInt(videos[i].height || 0)
        , offsetWidth = parseInt(videos[i].offsetWidth || 0);
      if (height > 0 && width > 0 && offsetWidth > 0 && offsetWidth !== width)
        $(videos[i]).css('height', (( height * offsetWidth ) / width ) + 'px');
      else
        $(videos[i]).removeAttr('style');
    }
  };

  Drupal.behaviors.theArkVideo = {
    attach: function () {
      var videos = $('.media-youtube-player, .media-vimeo-player');
      if (videos.length === 0) return;

      $(window).on('resize', function () {
        resizeMedia(videos);
      });
      resizeMedia(videos);
    }
  };
})(jQuery);

},{}],12:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkFacebookConfig = {
    attach: function () {
      var button = $('.facebook-share');
      if (button.length === 0) return;

      button.click(function (e) {
        e.preventDefault();
        if (!FB) return;
        var element = $(this);

        FB.ui({
          method: 'feed',
          link: element.prop('href'),
          picture: element.data('image'),
          name: element.data('title'),
          description: element.data('description')
        }, function (response) {});

        return false;
      });
    }
  };
})(jQuery);

},{}],13:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkHeadroomJSConfig = {
    attach: function () {
      var header = $('.l-regionwrapper--header')
        , social = $('.sidebar-navigation .menu');
      if (header.length === 0 || !Headroom) return;
      header.removeClass('no-js');
      social.addClass('menu-hidden');


      Headroom.options = Headroom.options || {};
      if ($('.front').length === 0) Headroom.options.offset = 40;
      else Headroom.options.offset = 200;

      Headroom.options.onTop = function () {
        social.addClass('menu-hidden');
      };
      Headroom.options.onNotTop = function () {
        social.removeClass('menu-hidden');
      };

      header.headroom();
    }
  };
})(jQuery);

},{}],14:[function(require,module,exports){
(function ($) {
  Drupal.behaviors.theArkTwitterConfig = {
    attach: function () {
      var button = $('.twitter-tweet');
      if (button.length === 0) return;

      button.click(function (e) {
        e.preventDefault();
        var width = 575
          , height = 250
          , left = ($(window).width()  - width)  / 2
          , top = ($(window).height() - height) / 2
          , url = $(this).prop('href')
          , opts = 'status=1' + ',width=' + width + ',height=' + height + ',top=' + top +',left=' + left;

        window.open(url, 'twitter', opts);
        return false;
      });
    }
  };
})(jQuery);

},{}]},{},[1])
//# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIm5vZGVfbW9kdWxlcy9icm93c2VyLXBhY2svX3ByZWx1ZGUuanMiLCJqcy1zcmMvdGhlLWFyay5qcyIsImpzLXNyYy9iZWhhdmlvcnMvY2FsZW5kYXIuanMiLCJqcy1zcmMvYmVoYXZpb3JzL2NvbHVtbmVkLXRleHQuanMiLCJqcy1zcmMvYmVoYXZpb3JzL2V2ZW50cy11cGNvbWluZy5qcyIsImpzLXNyYy9iZWhhdmlvcnMvZXhwYW5kYWJsZS1kZXRhaWxzLmpzIiwianMtc3JjL2JlaGF2aW9ycy9leHBhbmRlci5qcyIsImpzLXNyYy9iZWhhdmlvcnMvZm9vdGVyLWNvbnRhY3QuanMiLCJqcy1zcmMvYmVoYXZpb3JzL2hlYWRlci1uYXZpZ2F0aW9uLXByaW1hcnkuanMiLCJqcy1zcmMvYmVoYXZpb3JzL2hlYWRlci1zZWFyY2guanMiLCJqcy1zcmMvYmVoYXZpb3JzL3RhYnMuanMiLCJqcy1zcmMvYmVoYXZpb3JzL3ZpZGVvLmpzIiwianMtc3JjL2NvbmZpZy9mYWNlYm9vay5qcyIsImpzLXNyYy9jb25maWcvaGVhZHJvb20uanMiLCJqcy1zcmMvY29uZmlnL3R3aXR0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7QUNBQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUNuREE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQ3pDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUNyQkE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQ2hDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQ2xDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FDZEE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FDZkE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUNqREE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQ3pDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FDN0JBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUMxQkE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FDeEJBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FDekJBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBIiwiZmlsZSI6ImdlbmVyYXRlZC5qcyIsInNvdXJjZVJvb3QiOiIiLCJzb3VyY2VzQ29udGVudCI6WyIoZnVuY3Rpb24gZSh0LG4scil7ZnVuY3Rpb24gcyhvLHUpe2lmKCFuW29dKXtpZighdFtvXSl7dmFyIGE9dHlwZW9mIHJlcXVpcmU9PVwiZnVuY3Rpb25cIiYmcmVxdWlyZTtpZighdSYmYSlyZXR1cm4gYShvLCEwKTtpZihpKXJldHVybiBpKG8sITApO3ZhciBmPW5ldyBFcnJvcihcIkNhbm5vdCBmaW5kIG1vZHVsZSAnXCIrbytcIidcIik7dGhyb3cgZi5jb2RlPVwiTU9EVUxFX05PVF9GT1VORFwiLGZ9dmFyIGw9bltvXT17ZXhwb3J0czp7fX07dFtvXVswXS5jYWxsKGwuZXhwb3J0cyxmdW5jdGlvbihlKXt2YXIgbj10W29dWzFdW2VdO3JldHVybiBzKG4/bjplKX0sbCxsLmV4cG9ydHMsZSx0LG4scil9cmV0dXJuIG5bb10uZXhwb3J0c312YXIgaT10eXBlb2YgcmVxdWlyZT09XCJmdW5jdGlvblwiJiZyZXF1aXJlO2Zvcih2YXIgbz0wO288ci5sZW5ndGg7bysrKXMocltvXSk7cmV0dXJuIHN9KSIsIi8qKlxuICpcbiAqICAgc2RTU19TU1NTU1NicyAgIC5TICAgIFMuICAgICBzU1NzICAgICAgICAgLlNfU1NTcyAgICAgLlNfc1NTcyAgICAgLlMgICAgUy5cbiAqICAgWVNTU35TJVNTU1NTUCAgLlNTICAgIFNTLiAgIGQlJVNQICAgICAgICAuU1N+U1NTU1MgICAuU1N+WVMlJWIgICAuU1MgICAgU1MuXG4gKiAgICAgICAgUyVTICAgICAgIFMlUyAgICBTJVMgIGQlUycgICAgICAgICAgUyVTICAgU1NTUyAgUyVTICAgYFMlYiAgUyVTICAgIFMmU1xuICogICAgICAgIFMlUyAgICAgICBTJVMgICAgUyVTICBTJVMgICAgICAgICAgIFMlUyAgICBTJVMgIFMlUyAgICBTJVMgIFMlUyAgICBkKlNcbiAqICAgICAgICBTJlMgICAgICAgUyVTIFNTU1MlUyAgUyZTICAgICAgICAgICBTJVMgU1NTUyVTICBTJVMgICAgZCpTICBTJlMgICAuUypTXG4gKiAgICAgICAgUyZTICAgICAgIFMmUyAgU1NTJlMgIFMmU19TcyAgICAgICAgUyZTICBTU1MlUyAgUyZTICAgLlMqUyAgUyZTX3NkU1NTXG4gKiAgICAgICAgUyZTICAgICAgIFMmUyAgICBTJlMgIFMmU35TUCAgICAgICAgUyZTICAgIFMmUyAgUyZTX3NkU1NTICAgUyZTfllTU1klYlxuICogICAgICAgIFMmUyAgICAgICBTJlMgICAgUyZTICBTJlMgICAgICAgICAgIFMmUyAgICBTJlMgIFMmU35ZU1klYiAgIFMmUyAgICBgUyVcbiAqICAgICAgICBTKlMgICAgICAgUypTICAgIFMqUyAgUypiICAgICAgICAgICBTKlMgICAgUyZTICBTKlMgICBgUyViICBTKlMgICAgIFMlXG4gKiAgICAgICAgUypTICAgICAgIFMqUyAgICBTKlMgIFMqUy4gICAgICAgICAgUypTICAgIFMqUyAgUypTICAgIFMlUyAgUypTICAgICBTJlxuICogICAgICAgIFMqUyAgICAgICBTKlMgICAgUypTICAgU1NTYnMgICAgICAgIFMqUyAgICBTKlMgIFMqUyAgICBTJlMgIFMqUyAgICAgUyZcbiAqICAgICAgICBTKlMgICAgICAgU1NTICAgIFMqUyAgICBZU1NQICAgICAgICBTU1MgICAgUypTICBTKlMgICAgU1NTICBTKlMgICAgIFNTXG4gKiAgICAgICAgU1AgICAgICAgICAgICAgICBTUCAgICAgICAgICAgICAgICAgICAgICAgIFNQICAgU1AgICAgICAgICAgU1BcbiAqICAgICAgICBZICAgICAgICAgICAgICAgIFkgICAgICAgICAgICAgICAgICAgICAgICAgWSAgICBZICAgICAgICAgICBZXG4gKiAgICAgICAgICAgICBfICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICBfICAgICAgICBfIF9cbiAqICAgICAgICAgICAgfCB8ICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgKF8pICAgICAgfCAoXylcbiAqICAgX18gICAgICBffCB8X18gICBfX18gXyBfXyBfX18gICBfIF9fIF9fXyAgXyAgIF8gX19fIF8gIF9fXyAgfCB8X19fICAgX19fX18gIF9fX1xuICogICBcXCBcXCAvXFwgLyAvICdfIFxcIC8gXyBcXCAnX18vIF8gXFwgfCAnXyBgIF8gXFx8IHwgfCAvIF9ffCB8LyBfX3wgfCB8IFxcIFxcIC8gLyBfIFxcLyBfX3xcbiAqICAgIFxcIFYgIFYgL3wgfCB8IHwgIF9fLyB8IHwgIF9fLyB8IHwgfCB8IHwgfCB8X3wgXFxfXyBcXCB8IChfXyAgfCB8IHxcXCBWIC8gIF9fL1xcX18gXFxcbiAqICAgICBcXF8vXFxfLyB8X3wgfF98XFxfX198X3wgIFxcX19ffCB8X3wgfF98IHxffFxcX18sX3xfX18vX3xcXF9fX3wgfF98X3wgXFxfLyBcXF9fX3x8X19fL1xuICpcbiAqL1xuLypcbiAgQnJvd3NlcmlmeS9VZ2xpZnkgR2VuZXJhdGVkIEphdmFTY3JpcHQgZm9yIHRoZSBBcmsgLS0gaHR0cHM6Ly9naXRodWIuY29tL3FsdGQvdGhlLWFya1xuXG4gIC0gY29tcGlsZSB3aGlsZSBpbiAubnBtIGRpcmVjdG9yeSAoc2l0ZXMvYWxsL3RoZW1lcy90aGVfYXJrLy5ucG0pICAgICAgICAgICA6IGd1bHAganNcbiAgLSB3YXRjaCBmb3IgY2hhbmdlcyB3aGlsZSBpbiAubnBtIGRpcmVjdG9yeSAoc2l0ZXMvYWxsL3RoZW1lcy90aGVfYXJrLy5ucG0pIDogZ3VscCB3YXRjaFxuKi9cblxuLyoqXG4gKiBDb25maWd1cmF0aW9uXG4gKi9cbnJlcXVpcmUoJy4vY29uZmlnL2ZhY2Vib29rJyk7XG5yZXF1aXJlKCcuL2NvbmZpZy9oZWFkcm9vbScpO1xucmVxdWlyZSgnLi9jb25maWcvdHdpdHRlcicpO1xuXG4vKipcbiAqIENvbXBvbmVudHNcbiAqL1xucmVxdWlyZSgnLi9iZWhhdmlvcnMvY2FsZW5kYXInKTtcbnJlcXVpcmUoJy4vYmVoYXZpb3JzL2NvbHVtbmVkLXRleHQnKTtcbnJlcXVpcmUoJy4vYmVoYXZpb3JzL2V4cGFuZGFibGUtZGV0YWlscycpO1xucmVxdWlyZSgnLi9iZWhhdmlvcnMvZXZlbnRzLXVwY29taW5nJyk7XG5yZXF1aXJlKCcuL2JlaGF2aW9ycy9leHBhbmRlcicpO1xucmVxdWlyZSgnLi9iZWhhdmlvcnMvZm9vdGVyLWNvbnRhY3QnKTtcbnJlcXVpcmUoJy4vYmVoYXZpb3JzL2hlYWRlci1uYXZpZ2F0aW9uLXByaW1hcnknKTtcbnJlcXVpcmUoJy4vYmVoYXZpb3JzL2hlYWRlci1zZWFyY2gnKTtcbnJlcXVpcmUoJy4vYmVoYXZpb3JzL3RhYnMnKTtcbnJlcXVpcmUoJy4vYmVoYXZpb3JzL3ZpZGVvJyk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcblxuICBmdW5jdGlvbiB0b2dnbGVQYXN0RXZlbnRzVGV4dCAoYWN0aW9uKSB7XG4gICAgcmV0dXJuICdDbGljayB0byAnICsgYWN0aW9uICsgJyBQYXN0IEV2ZW50cyc7XG4gIH1cblxuICBEcnVwYWwuYmVoYXZpb3JzLnRoZUFya0NhbGVuZGFyID0ge1xuICAgIGF0dGFjaDogZnVuY3Rpb24gKCkge1xuICAgICAgdmFyIGNvbnRhaW5lciA9ICQoJy5jYWxlbmRhci1ib2R5Jyk7XG4gICAgICBpZiAoY29udGFpbmVyLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICB2YXIgZGF0ZU5hdiA9ICQoJy5kYXRlLW5hdicpLmNsb25lKCk7XG4gICAgICBkYXRlTmF2LmNoaWxkcmVuKCcuZGF0ZS1oZWFkaW5nJykucmVtb3ZlKCk7XG4gICAgICBjb250YWluZXIuYXBwZW5kKGRhdGVOYXYpO1xuXG4gICAgICB2YXIgdG9kYXkgPSBjb250YWluZXIuZmluZCgnLnRvZGF5Jyk7XG4gICAgICBpZiAodG9kYXkubGVuZ3RoID09PSAwKSByZXR1cm47XG5cbiAgICAgIHZhciBwYXN0ID0gY29udGFpbmVyLmZpbmQoJy5wYXN0Jyk7XG4gICAgICBpZiAocGFzdC5sZW5ndGggPT09IDApIHJldHVybjtcblxuICAgICAgdmFyIHRvZ2dsZUNvbnRhaW5lciA9ICQoJzxkaXYgY2xhc3M9XCJzaG93LXBhc3QtdG9nZ2xlLWNvbnRhaW5lclwiPjwvZGl2PicpXG4gICAgICAgICwgdG9nZ2xlID0gJCgnPGEgY2xhc3M9XCJzaG93LXBhc3QtdG9nZ2xlXCIgcm9sZT1cImJ1dHRvblwiPjwvZGl2PicpO1xuXG4gICAgICB0b2dnbGUudGV4dCh0b2dnbGVQYXN0RXZlbnRzVGV4dCgnU2hvdycpKTtcbiAgICAgIHRvZ2dsZUNvbnRhaW5lci5hcHBlbmQodG9nZ2xlKTtcbiAgICAgIGNvbnRhaW5lci5wcmVwZW5kKHRvZ2dsZUNvbnRhaW5lcik7XG4gICAgICBwYXN0LmFkZENsYXNzKCdwYXN0LWhpZGRlbicpO1xuXG4gICAgICB0b2dnbGUub24oJ3RhcCcsIGZ1bmN0aW9uICgpIHtcbiAgICAgICAgaWYgKHBhc3QuaGFzQ2xhc3MoJ3Bhc3QtaGlkZGVuJykpIHtcbiAgICAgICAgICBwYXN0LnJlbW92ZUNsYXNzKCdwYXN0LWhpZGRlbicpO1xuICAgICAgICAgIHRvZ2dsZS50ZXh0KHRvZ2dsZVBhc3RFdmVudHNUZXh0KCdIaWRlJykpO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgIHBhc3QuYWRkQ2xhc3MoJ3Bhc3QtaGlkZGVuJyk7XG4gICAgICAgICAgdG9nZ2xlLnRleHQodG9nZ2xlUGFzdEV2ZW50c1RleHQoJ1Nob3cnKSk7XG4gICAgICAgIH1cbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtDb2x1bW5lZFRleHQgPSB7XG4gICAgYXR0YWNoOiBmdW5jdGlvbiAoKSB7XG4gICAgICB2YXIgaXRlbSA9ICQoJy5jb2x1bW5lZC10ZXh0LWl0ZW0nKTtcbiAgICAgIGlmIChpdGVtLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICB2YXIgaGVhZGluZ3MgPSBpdGVtLmZpbmQoJ2gzLCBoNCwgaDUsIGg2Jyk7XG4gICAgICBoZWFkaW5ncy5lYWNoKGZ1bmN0aW9uIChpbmRleCkge1xuICAgICAgICB2YXIgc2VsZiA9ICQodGhpcylcbiAgICAgICAgICAsIHNpYmxpbmcgPSBzZWxmLm5leHQoKTtcblxuICAgICAgICBpZiAoIXNpYmxpbmcubGVuZ3RoKSByZXR1cm47XG4gICAgICAgIHZhciByZXBsYWNlbWVudCA9ICQoJzxkaXYgY2xhc3M9XCJ0aXRsZS1jb250ZW50LXBhaXJcIj48L2Rpdj4nKS5odG1sKHNlbGYuY2xvbmUoKSk7XG4gICAgICAgIHJlcGxhY2VtZW50LmFwcGVuZChzaWJsaW5nLmNsb25lKCkpO1xuICAgICAgICBzaWJsaW5nLmFmdGVyKHJlcGxhY2VtZW50KTtcbiAgICAgICAgc2VsZi5yZW1vdmUoKTtcbiAgICAgICAgc2libGluZy5yZW1vdmUoKTtcbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcblxuICBmdW5jdGlvbiB0b2dnbGVVcGNvbWluZ0V2ZW50c1RleHQgKGFjdGlvbikge1xuICAgIHJldHVybiAnQ2xpY2sgdG8gJyArIGFjdGlvbiArICcgTW9yZSBVcGNvbWluZyBFdmVudHMnO1xuICB9XG5cbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtFdmVudHNVcGNvbWluZyA9IHtcbiAgICBhdHRhY2g6IGZ1bmN0aW9uICgpIHtcbiAgICAgIHZhciBjb250YWluZXIgPSAkKCcuZXZlbnRzLXVwY29taW5nLXZpZXcnKVxuICAgICAgICAsIGV2ZW50cyA9ICQoJy5jYWxlbmRhci1jb2x1bW4nKS5ub3QoJy5maXJzdCcpO1xuICAgICAgaWYgKGNvbnRhaW5lci5sZW5ndGggPT09IDAgfHwgZXZlbnRzLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICB2YXIgdG9nZ2xlQ29udGFpbmVyID0gJCgnPGRpdiBjbGFzcz1cInNob3ctdXBjb21pbmctdG9nZ2xlLWNvbnRhaW5lclwiPjwvZGl2PicpXG4gICAgICAgICwgdG9nZ2xlID0gJCgnPGEgY2xhc3M9XCJzaG93LXVwY29taW5nLXRvZ2dsZVwiIHJvbGU9XCJidXR0b25cIj48L2Rpdj4nKTtcblxuICAgICAgdG9nZ2xlLnRleHQodG9nZ2xlVXBjb21pbmdFdmVudHNUZXh0KCdTaG93JykpO1xuICAgICAgdG9nZ2xlQ29udGFpbmVyLmFwcGVuZCh0b2dnbGUpO1xuICAgICAgY29udGFpbmVyLmFwcGVuZCh0b2dnbGVDb250YWluZXIpO1xuICAgICAgZXZlbnRzLmFkZENsYXNzKCd1cGNvbWluZy1oaWRkZW4nKTtcblxuICAgICAgdG9nZ2xlLm9uKCd0YXAnLCBmdW5jdGlvbiAoKSB7XG4gICAgICAgIGlmIChldmVudHMuaGFzQ2xhc3MoJ3VwY29taW5nLWhpZGRlbicpKSB7XG4gICAgICAgICAgZXZlbnRzLnJlbW92ZUNsYXNzKCd1cGNvbWluZy1oaWRkZW4nKTtcbiAgICAgICAgICB0b2dnbGUudGV4dCh0b2dnbGVVcGNvbWluZ0V2ZW50c1RleHQoJ0hpZGUnKSk7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgZXZlbnRzLmFkZENsYXNzKCd1cGNvbWluZy1oaWRkZW4nKTtcbiAgICAgICAgICB0b2dnbGUudGV4dCh0b2dnbGVVcGNvbWluZ0V2ZW50c1RleHQoJ1Nob3cnKSk7XG4gICAgICAgIH1cbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcblxuICBmdW5jdGlvbiBleHBhbmRhYmxlRGV0YWlsc1RvZ2dsZSAoZWxlbSkge1xuICAgIHZhciBwYXJlbnQgPSBlbGVtLnBhcmVudHMoJy5leHBhbmRhYmxlLWRldGFpbHMtaXRlbScpXG4gICAgICAsIGV4cGFuZGVyID0gcGFyZW50LmZpbmQoJy5leHBhbmRhYmxlLWRldGFpbHMtZXhwYW5kZXInKVxuICAgICAgLCBleHBhbmRlckxhYmVsID0gZXhwYW5kZXIubGVuZ3RoICYmIGV4cGFuZGVyLmF0dHIoJ2RhdGEtZXhwYW5kZXItbGFiZWwnKSA/XG4gICAgICAgICAgZXhwYW5kZXIuYXR0cignZGF0YS1leHBhbmRlci1sYWJlbCcpIDpcbiAgICAgICAgICAnSXRlbSc7XG5cbiAgICBpZiAocGFyZW50Lmhhc0NsYXNzKCdleHBhbmRhYmxlLWRldGFpbHMtaXRlbS1jb2xsYXBzZWQnKSlcbiAgICAgIGV4cGFuZGVyLnRleHQoJ0Nsb3NlICcgKyBleHBhbmRlckxhYmVsKTtcbiAgICBlbHNlXG4gICAgICBleHBhbmRlci50ZXh0KCdWaWV3ICcgKyBleHBhbmRlckxhYmVsKTtcblxuICAgIHBhcmVudC50b2dnbGVDbGFzcygnZXhwYW5kYWJsZS1kZXRhaWxzLWl0ZW0tY29sbGFwc2VkJyk7XG4gIH1cblxuICBEcnVwYWwuYmVoYXZpb3JzLnRoZUFya0V4cGFuZGFibGVEZXRhaWxzID0ge1xuICAgIGF0dGFjaDogZnVuY3Rpb24gKCkge1xuICAgICAgdmFyIGV4cGFuZGVycyA9ICQoJy5leHBhbmRhYmxlLWRldGFpbHMtdGl0bGUsIC5leHBhbmRhYmxlLWRldGFpbHMtZXhwYW5kZXInKVxuICAgICAgICAsIGl0ZW1zID0gJCgnLmV4cGFuZGFibGUtZGV0YWlscy1pdGVtJyk7XG5cbiAgICAgIGlmICghZXhwYW5kZXJzLmxlbmd0aCB8fCAhaXRlbXMubGVuZ3RoKSByZXR1cm47XG5cbiAgICAgICQoJy5leHBhbmRhYmxlLWRldGFpbHMtZXhwYW5kZXInKS5lYWNoKGZ1bmN0aW9uIChpbmRleCwgZXhwYW5kZXIpIHtcbiAgICAgICAgZXhwYW5kYWJsZURldGFpbHNUb2dnbGUoJChleHBhbmRlcikpO1xuICAgICAgfSk7XG5cbiAgICAgIGV4cGFuZGVycy5vbigndGFwJywgZnVuY3Rpb24gKCkge1xuICAgICAgICBleHBhbmRhYmxlRGV0YWlsc1RvZ2dsZSgkKHRoaXMpKTtcbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtFeHBhbmRlciA9IHtcbiAgICBhdHRhY2g6IGZ1bmN0aW9uICgpIHtcbiAgICAgIHZhciBleHBhbmRlcnMgPSAkKCcuZXhwYW5kZXInKTtcbiAgICAgIGlmIChleHBhbmRlcnMubGVuZ3RoID09PSAwKSByZXR1cm47XG5cbiAgICAgIGV4cGFuZGVycy5hZGRDbGFzcygnZXhwYW5kZXItY29sbGFwc2VkJyk7XG4gICAgICBleHBhbmRlcnMub24oJ3RhcCcsIGZ1bmN0aW9uICgpIHtcbiAgICAgICAgJCh0aGlzKS50b2dnbGVDbGFzcygnZXhwYW5kZXItY29sbGFwc2VkJyk7XG4gICAgICAgIERydXBhbC5iZWhhdmlvcnMudGhlQXJrVmlkZW8uYXR0YWNoKCk7XG4gICAgICB9KTtcbiAgICB9XG4gIH07XG59KShqUXVlcnkpO1xuIiwiKGZ1bmN0aW9uICgkKSB7XG4gIERydXBhbC5iZWhhdmlvcnMudGhlQXJrRm9vdGVyQ29udGFjdCA9IHtcbiAgICBhdHRhY2g6IGZ1bmN0aW9uICgpIHtcbiAgICAgIHZhciBibG9jayA9ICQoJy5mb290ZXItY29udGFjdCcpXG4gICAgICAgICwgcGhvbmVOdW1iZXJzID0gJCgnLmZvb3Rlci1jb250YWN0IC5waG9uZScpO1xuICAgICAgaWYgKGJsb2NrLmxlbmd0aCA9PT0gMCB8fCBwaG9uZU51bWJlcnMubGVuZ3RoID09PSAwKSByZXR1cm47XG5cbiAgICAgIHBob25lTnVtYmVycy5lYWNoKGZ1bmN0aW9uICgpIHsgLy8gZW5zdXJlIGhyZWYgZm9yIGVhY2ggcGhvbmUgbGluayBwb2ludHMgdG8gdGhlIGNvcnJlY3QgcGhvbmUgbnVtYmVyXG4gICAgICAgIHZhciBudW1iZXIgPSAkKHRoaXMpLnRleHQoKTtcbiAgICAgICAgaWYgKCFudW1iZXIpIHJldHVybjtcbiAgICAgICAgJCh0aGlzKS5hdHRyKCdocmVmJywgJ3RlbDorJyArIG51bWJlci5yZXBsYWNlKC9cXEQvZywnJykpO1xuICAgICAgfSk7XG4gICAgfVxuICB9O1xufSkoalF1ZXJ5KTtcbiIsIihmdW5jdGlvbiAoJCkge1xuICBEcnVwYWwuYmVoYXZpb3JzLnRoZUFya0hlYWRlck5hdmlnYXRpb25QcmltYXJ5ID0ge1xuICAgIGF0dGFjaDogZnVuY3Rpb24gKCkge1xuICAgICAgdmFyIGJvZHkgPSAkKCdib2R5JylcbiAgICAgICAgLCB3cmFwcGVyID0gJCgnLm1lbnUtcHJpbWFyeS13cmFwcGVyJylcbiAgICAgICAgLCBuYXZpZ2F0aW9uID0gJCgnLm1lbnUtcHJpbWFyeS13cmFwcGVyID4gLm1lbnUnKVxuICAgICAgICAsIHRvZ2dsZSA9ICQoJy5oZWFkZXItbmF2aWdhdGlvbi1wcmltYXJ5IC5ibG9ja19fdGl0bGUnKVxuICAgICAgICAsIGJ1dHRvbkNsb3NlID0gJCgnLm1lbnUtcHJpbWFyeS1jbG9zZScpO1xuICAgICAgaWYgKHdyYXBwZXIubGVuZ3RoID09PSAwIHx8IG5hdmlnYXRpb24ubGVuZ3RoID09PSAwKSByZXR1cm47XG5cbiAgICAgIHZhciB0b2dnbGVDbGFzc2VzID0gZnVuY3Rpb24gKG1ldGhvZCkge1xuICAgICAgICBib2R5W21ldGhvZF0oJ2RvY3VtZW50LW1vZGFsLW1vYmlsZScpO1xuICAgICAgICB0b2dnbGVbbWV0aG9kXSgnYWN0aXZlJyk7XG4gICAgICAgIHdyYXBwZXJbbWV0aG9kXSgnbWVudS1mbHlvdXQtdmlzaWJsZScpO1xuICAgICAgICBzd2l0Y2ggKG1ldGhvZCkge1xuICAgICAgICAgIGNhc2UgJ2FkZENsYXNzJzpcbiAgICAgICAgICAgIHRvZ2dsZS5vZmYoJ3RhcCcpO1xuXG4gICAgICAgICAgICAkKGRvY3VtZW50KS5vbigndG91Y2htb3ZlJywgZnVuY3Rpb24gKGUpIHtcbiAgICAgICAgICAgICAgZS5wcmV2ZW50RGVmYXVsdCgpO1xuICAgICAgICAgICAgfSk7XG4gICAgICAgICAgICBuYXZpZ2F0aW9uLm9uKCd0b3VjaG1vdmUnLCBmdW5jdGlvbiAoZSkge1xuICAgICAgICAgICAgICBlLnN0b3BQcm9wYWdhdGlvbigpO1xuICAgICAgICAgICAgfSk7XG4gICAgICAgICAgICBidXR0b25DbG9zZS5vbigndGFwJywgZnVuY3Rpb24gKCkge1xuICAgICAgICAgICAgICB0b2dnbGVDbGFzc2VzKCdyZW1vdmVDbGFzcycpO1xuICAgICAgICAgICAgfSk7XG5cbiAgICAgICAgICAgIGJyZWFrO1xuICAgICAgICAgIGNhc2UgJ3JlbW92ZUNsYXNzJzpcbiAgICAgICAgICAgICQoZG9jdW1lbnQpLm9mZigndG91Y2htb3ZlJyk7XG4gICAgICAgICAgICBuYXZpZ2F0aW9uLm9mZigndG91Y2htb3ZlJyk7XG4gICAgICAgICAgICBidXR0b25DbG9zZS5vZmYoJ3RhcCcpO1xuXG4gICAgICAgICAgICBkZWZhdWx0TGlzdGVuZXJzKCk7XG4gICAgICAgICAgICBicmVhaztcbiAgICAgICAgfVxuICAgICAgfTtcblxuICAgICAgdmFyIGRlZmF1bHRMaXN0ZW5lcnMgPSBmdW5jdGlvbiAoKSB7XG4gICAgICAgIHRvZ2dsZS5vbigndGFwJywgZnVuY3Rpb24gKCkge1xuICAgICAgICAgIHRvZ2dsZUNsYXNzZXMoJ2FkZENsYXNzJyk7XG4gICAgICAgIH0pO1xuICAgICAgfTtcbiAgICAgIGRlZmF1bHRMaXN0ZW5lcnMoKTtcblxuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtIZWFkZXJTZWFyY2ggPSB7XG4gICAgYXR0YWNoOiBmdW5jdGlvbiAoKSB7XG4gICAgICB2YXIgYmxvY2sgPSAkKCcuaGVhZGVyLXNlYXJjaCcpXG4gICAgICAgICwgZG9jID0gJChkb2N1bWVudClcbiAgICAgICAgLCBmb3JtID0gJCgnLmhlYWRlci1zZWFyY2ggLnNlYXJjaC1ibG9jay1mb3JtJylcbiAgICAgICAgLCBzdWJtaXQgPSAkKCcuaGVhZGVyLXNlYXJjaCAuZm9ybS1zdWJtaXQnKVxuICAgICAgICAsIHRleHQgPSAkKCcuaGVhZGVyLXNlYXJjaCAuZm9ybS10ZXh0JylcbiAgICAgICAgLCB0ZXh0Q29udGFpbmVyID0gJCgnLmhlYWRlci1zZWFyY2ggLmZvcm0tdHlwZS10ZXh0ZmllbGQnKTtcblxuICAgICAgaWYgKGJsb2NrLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICBzdWJtaXQub24oJ3RhcCcsIGZ1bmN0aW9uIChldmVudCkge1xuICAgICAgICBldmVudC5wcmV2ZW50RGVmYXVsdCgpO1xuICAgICAgICBldmVudC5zdG9wUHJvcGFnYXRpb24oKTtcblxuICAgICAgICBpZiAodGV4dENvbnRhaW5lci5oYXNDbGFzcygnZm9ybS10eXBlLXRleHRmaWVsZC1hY3RpdmUnKSkge1xuICAgICAgICAgIHRleHRDb250YWluZXIucmVtb3ZlQ2xhc3MoJ2Zvcm0tdHlwZS10ZXh0ZmllbGQtYWN0aXZlJyk7XG4gICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgdGV4dENvbnRhaW5lci5hZGRDbGFzcygnZm9ybS10eXBlLXRleHRmaWVsZC1hY3RpdmUnKTtcbiAgICAgICAgICB0ZXh0LmZvY3VzKCk7XG5cbiAgICAgICAgICBkb2Mub24oJ3RhcCcsIGZ1bmN0aW9uIChldmVudCkge1xuICAgICAgICAgICAgdGV4dENvbnRhaW5lci5yZW1vdmVDbGFzcygnZm9ybS10eXBlLXRleHRmaWVsZC1hY3RpdmUnKTtcbiAgICAgICAgICAgIGRvYy5vZmYoJ3RhcCcpO1xuICAgICAgICAgIH0pO1xuICAgICAgICB9XG4gICAgICB9KTtcblxuICAgICAgc3VibWl0Lm9uKCdjbGljaycsIGZ1bmN0aW9uIChldmVudCkge1xuICAgICAgICBldmVudC5wcmV2ZW50RGVmYXVsdCgpO1xuICAgICAgICBpZiAodGV4dC52YWwoKSkgZm9ybS5zdWJtaXQoKTtcbiAgICAgICAgZWxzZSBpZiAodGV4dENvbnRhaW5lci5oYXNDbGFzcygnZm9ybS10eXBlLXRleHRmaWVsZC1hY3RpdmUnKSkgdGV4dC5mb2N1cygpO1xuICAgICAgfSk7XG5cbiAgICAgIHRleHQub24oJ3RhcCcsIGZ1bmN0aW9uIChldmVudCkge1xuICAgICAgICBldmVudC5zdG9wUHJvcGFnYXRpb24oKTtcbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgZnVuY3Rpb24gdGFiVG9nZ2xlICh0YWJJZCwgY29udGFpbmVycywgdG9nZ2xlcykge1xuICAgIHRvZ2dsZXMucmVtb3ZlQ2xhc3MoJ3RhYi10b2dnbGUtYWN0aXZlJyk7XG4gICAgY29udGFpbmVycy5yZW1vdmVDbGFzcygndGFiLWNvbnRhaW5lci1hY3RpdmUnKTtcblxuICAgIHRvZ2dsZXMuZmlsdGVyKCdbZGF0YS10YWItdG9nZ2xlLWlkPVwiJyArIHRhYklkICsgJ1wiXScpLmFkZENsYXNzKCd0YWItdG9nZ2xlLWFjdGl2ZScpO1xuICAgIGNvbnRhaW5lcnMuZmlsdGVyKCdbZGF0YS10YWItaWQ9XCInKyB0YWJJZCArJ1wiXScpLmFkZENsYXNzKCd0YWItY29udGFpbmVyLWFjdGl2ZScpO1xuICB9XG5cbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtUYWJzID0ge1xuICAgIGF0dGFjaDogZnVuY3Rpb24gKCkge1xuICAgICAgdmFyIGNvbnRhaW5lcnMgPSAkKCcudGFiLWNvbnRhaW5lcicpXG4gICAgICAgICwgdG9nZ2xlcyA9ICQoJy50YWItdG9nZ2xlJyk7XG4gICAgICBpZiAoY29udGFpbmVycy5sZW5ndGggPT09IDAgfHwgdG9nZ2xlcy5sZW5ndGggPT09IDApIHJldHVybjtcblxuICAgICAgdGFiVG9nZ2xlKCQodG9nZ2xlc1swXSkuYXR0cignZGF0YS10YWItdG9nZ2xlLWlkJyksIGNvbnRhaW5lcnMsIHRvZ2dsZXMpO1xuXG4gICAgICB0b2dnbGVzLm9uKCdjbGljaycsIGZ1bmN0aW9uIChlKSB7XG4gICAgICAgIGUucHJldmVudERlZmF1bHQoKTtcbiAgICAgIH0pO1xuXG4gICAgICB0b2dnbGVzLm9uKCd0YXAnLCBmdW5jdGlvbiAoKSB7XG4gICAgICAgIHZhciB0YWJJZCA9ICQodGhpcykuYXR0cignZGF0YS10YWItdG9nZ2xlLWlkJyk7XG4gICAgICAgIGlmICghdGFiSWQpIHJldHVybjtcbiAgICAgICAgdGFiVG9nZ2xlKHRhYklkLCBjb250YWluZXJzLCB0b2dnbGVzKTtcbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgdmFyIHJlc2l6ZU1lZGlhID0gZnVuY3Rpb24gKHZpZGVvcykge1xuICAgIHZhciBpID0gdmlkZW9zLmxlbmd0aDtcbiAgICB3aGlsZSAoaS0tKSB7XG4gICAgICB2YXIgd2lkdGggPSBwYXJzZUludCh2aWRlb3NbaV0ud2lkdGggfHwgMClcbiAgICAgICAgLCBoZWlnaHQgPSBwYXJzZUludCh2aWRlb3NbaV0uaGVpZ2h0IHx8IDApXG4gICAgICAgICwgb2Zmc2V0V2lkdGggPSBwYXJzZUludCh2aWRlb3NbaV0ub2Zmc2V0V2lkdGggfHwgMCk7XG4gICAgICBpZiAoaGVpZ2h0ID4gMCAmJiB3aWR0aCA+IDAgJiYgb2Zmc2V0V2lkdGggPiAwICYmIG9mZnNldFdpZHRoICE9PSB3aWR0aClcbiAgICAgICAgJCh2aWRlb3NbaV0pLmNzcygnaGVpZ2h0JywgKCggaGVpZ2h0ICogb2Zmc2V0V2lkdGggKSAvIHdpZHRoICkgKyAncHgnKTtcbiAgICAgIGVsc2VcbiAgICAgICAgJCh2aWRlb3NbaV0pLnJlbW92ZUF0dHIoJ3N0eWxlJyk7XG4gICAgfVxuICB9O1xuXG4gIERydXBhbC5iZWhhdmlvcnMudGhlQXJrVmlkZW8gPSB7XG4gICAgYXR0YWNoOiBmdW5jdGlvbiAoKSB7XG4gICAgICB2YXIgdmlkZW9zID0gJCgnLm1lZGlhLXlvdXR1YmUtcGxheWVyLCAubWVkaWEtdmltZW8tcGxheWVyJyk7XG4gICAgICBpZiAodmlkZW9zLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICAkKHdpbmRvdykub24oJ3Jlc2l6ZScsIGZ1bmN0aW9uICgpIHtcbiAgICAgICAgcmVzaXplTWVkaWEodmlkZW9zKTtcbiAgICAgIH0pO1xuICAgICAgcmVzaXplTWVkaWEodmlkZW9zKTtcbiAgICB9XG4gIH07XG59KShqUXVlcnkpO1xuIiwiKGZ1bmN0aW9uICgkKSB7XG4gIERydXBhbC5iZWhhdmlvcnMudGhlQXJrRmFjZWJvb2tDb25maWcgPSB7XG4gICAgYXR0YWNoOiBmdW5jdGlvbiAoKSB7XG4gICAgICB2YXIgYnV0dG9uID0gJCgnLmZhY2Vib29rLXNoYXJlJyk7XG4gICAgICBpZiAoYnV0dG9uLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICBidXR0b24uY2xpY2soZnVuY3Rpb24gKGUpIHtcbiAgICAgICAgZS5wcmV2ZW50RGVmYXVsdCgpO1xuICAgICAgICBpZiAoIUZCKSByZXR1cm47XG4gICAgICAgIHZhciBlbGVtZW50ID0gJCh0aGlzKTtcblxuICAgICAgICBGQi51aSh7XG4gICAgICAgICAgbWV0aG9kOiAnZmVlZCcsXG4gICAgICAgICAgbGluazogZWxlbWVudC5wcm9wKCdocmVmJyksXG4gICAgICAgICAgcGljdHVyZTogZWxlbWVudC5kYXRhKCdpbWFnZScpLFxuICAgICAgICAgIG5hbWU6IGVsZW1lbnQuZGF0YSgndGl0bGUnKSxcbiAgICAgICAgICBkZXNjcmlwdGlvbjogZWxlbWVudC5kYXRhKCdkZXNjcmlwdGlvbicpXG4gICAgICAgIH0sIGZ1bmN0aW9uIChyZXNwb25zZSkge30pO1xuXG4gICAgICAgIHJldHVybiBmYWxzZTtcbiAgICAgIH0pO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtIZWFkcm9vbUpTQ29uZmlnID0ge1xuICAgIGF0dGFjaDogZnVuY3Rpb24gKCkge1xuICAgICAgdmFyIGhlYWRlciA9ICQoJy5sLXJlZ2lvbndyYXBwZXItLWhlYWRlcicpXG4gICAgICAgICwgc29jaWFsID0gJCgnLnNpZGViYXItbmF2aWdhdGlvbiAubWVudScpO1xuICAgICAgaWYgKGhlYWRlci5sZW5ndGggPT09IDAgfHwgIUhlYWRyb29tKSByZXR1cm47XG4gICAgICBoZWFkZXIucmVtb3ZlQ2xhc3MoJ25vLWpzJyk7XG4gICAgICBzb2NpYWwuYWRkQ2xhc3MoJ21lbnUtaGlkZGVuJyk7XG5cblxuICAgICAgSGVhZHJvb20ub3B0aW9ucyA9IEhlYWRyb29tLm9wdGlvbnMgfHwge307XG4gICAgICBpZiAoJCgnLmZyb250JykubGVuZ3RoID09PSAwKSBIZWFkcm9vbS5vcHRpb25zLm9mZnNldCA9IDQwO1xuICAgICAgZWxzZSBIZWFkcm9vbS5vcHRpb25zLm9mZnNldCA9IDIwMDtcblxuICAgICAgSGVhZHJvb20ub3B0aW9ucy5vblRvcCA9IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgc29jaWFsLmFkZENsYXNzKCdtZW51LWhpZGRlbicpO1xuICAgICAgfTtcbiAgICAgIEhlYWRyb29tLm9wdGlvbnMub25Ob3RUb3AgPSBmdW5jdGlvbiAoKSB7XG4gICAgICAgIHNvY2lhbC5yZW1vdmVDbGFzcygnbWVudS1oaWRkZW4nKTtcbiAgICAgIH07XG5cbiAgICAgIGhlYWRlci5oZWFkcm9vbSgpO1xuICAgIH1cbiAgfTtcbn0pKGpRdWVyeSk7XG4iLCIoZnVuY3Rpb24gKCQpIHtcbiAgRHJ1cGFsLmJlaGF2aW9ycy50aGVBcmtUd2l0dGVyQ29uZmlnID0ge1xuICAgIGF0dGFjaDogZnVuY3Rpb24gKCkge1xuICAgICAgdmFyIGJ1dHRvbiA9ICQoJy50d2l0dGVyLXR3ZWV0Jyk7XG4gICAgICBpZiAoYnV0dG9uLmxlbmd0aCA9PT0gMCkgcmV0dXJuO1xuXG4gICAgICBidXR0b24uY2xpY2soZnVuY3Rpb24gKGUpIHtcbiAgICAgICAgZS5wcmV2ZW50RGVmYXVsdCgpO1xuICAgICAgICB2YXIgd2lkdGggPSA1NzVcbiAgICAgICAgICAsIGhlaWdodCA9IDI1MFxuICAgICAgICAgICwgbGVmdCA9ICgkKHdpbmRvdykud2lkdGgoKSAgLSB3aWR0aCkgIC8gMlxuICAgICAgICAgICwgdG9wID0gKCQod2luZG93KS5oZWlnaHQoKSAtIGhlaWdodCkgLyAyXG4gICAgICAgICAgLCB1cmwgPSAkKHRoaXMpLnByb3AoJ2hyZWYnKVxuICAgICAgICAgICwgb3B0cyA9ICdzdGF0dXM9MScgKyAnLHdpZHRoPScgKyB3aWR0aCArICcsaGVpZ2h0PScgKyBoZWlnaHQgKyAnLHRvcD0nICsgdG9wICsnLGxlZnQ9JyArIGxlZnQ7XG5cbiAgICAgICAgd2luZG93Lm9wZW4odXJsLCAndHdpdHRlcicsIG9wdHMpO1xuICAgICAgICByZXR1cm4gZmFsc2U7XG4gICAgICB9KTtcbiAgICB9XG4gIH07XG59KShqUXVlcnkpO1xuIl19
